#ifndef DGUIAPPLICATIONHELPER_H
#define DGUIAPPLICATIONHELPER_H

#include <QObject>
#include <QWidget>
#include <QLocale>
#include "dpalette.h"
#include "dplatformtheme.h"

class DGuiApplicationHelper
{
    Q_PROPERTY(ColorType themeType READ themeType NOTIFY themeTypeChanged)
    Q_PROPERTY(ColorType paletteType READ paletteType WRITE setPaletteType NOTIFY paletteTypeChanged)
    Q_PROPERTY(bool hasUserManual READ hasUserManual)
public:
    enum ColorType {
        UnknownType,
        LightType,
        DarkType
    };

    enum SingleScope {
        UserScope,
        GroupScope,
        WorldScope
    };

    enum SizeMode {
        NormalMode,
        CompactMode
    };

    enum Attribute {
        UseInactiveColorGroup    = 1 << 0,
        ColorCompositing         = 1 << 1,
        DontSaveApplicationTheme = 1 << 2,

        /* readonly flag */
        ReadOnlyLimit            = 1 << 22,
        IsDeepinPlatformTheme    = ReadOnlyLimit << 0,
        IsDXcbPlatform           = ReadOnlyLimit << 1,
        IsXWindowPlatform        = ReadOnlyLimit << 2,
        IsTableEnvironment       = ReadOnlyLimit << 3,
        IsDeepinEnvironment      = ReadOnlyLimit << 4,
        IsSpecialEffectsEnvironment = ReadOnlyLimit << 5
    };

    Q_DECLARE_FLAGS(Attributes, Attribute)

    typedef DGuiApplicationHelper *(*HelperCreator)();
    //D_DECL_DEPRECATED static void registerInstanceCreator(HelperCreator creator);
    Q_DECL_DEPRECATED static void registerInstanceCreator(HelperCreator creator);

    DGuiApplicationHelper();
    static DGuiApplicationHelper *instance();
        ~DGuiApplicationHelper();

    static QColor adjustColor(const QColor &base, qint8 hueFloat, qint8 saturationFloat, qint8 lightnessFloat,
                                  qint8 redFloat, qint8 greenFloat, qint8 blueFloat, qint8 alphaFloat);
    static QImage adjustColor(const QImage &base, qint8 hueFloat, qint8 saturationFloat, qint8 lightnessFloat,
                                  qint8 redFloat, qint8 greenFloat, qint8 blueFloat, qint8 alphaFloat);
    static QColor blendColor(const QColor &substrate, const QColor &superstratum);
    static DPalette standardPalette(ColorType type);
    static void generatePaletteColor(DPalette &base, QPalette::ColorRole role, ColorType type);
    static void generatePaletteColor(DPalette &base, DPalette::ColorType role, ColorType type);
    static void generatePalette(DPalette &base, ColorType type = UnknownType);
    static DPalette fetchPalette(const DPlatformTheme *theme);

    Q_DECL_DEPRECATED_X("Use UseInactiveColorGroup enum with setAttribute.") static void setUseInactiveColorGroup(bool on);
    Q_DECL_DEPRECATED_X("Use ColorCompositing enum with setAttribute.") static void setColorCompositingEnabled(bool on);

    static bool isXWindowPlatform();
    static bool isTabletEnvironment();
    static bool isSpecialEffectsEnvironment();
    static void setAttribute(Attribute attribute, bool enable);
    static bool testAttribute(Attribute attribute);

    DPlatformTheme *systemTheme() const;
    DPlatformTheme *applicationTheme() const;

    //D_DECL_DEPRECATED DPlatformTheme *windowTheme(QWindow *window) const;

    DPalette applicationPalette() const;
    DPalette applicationPalette(ColorType paletteType) const;
    void setApplicationPalette(const DPalette &palette);

    //D_DECL_DEPRECATED DPalette windowPalette(QWindow *window) const;

    //const DFontManager *fontManager() const;

    static ColorType toColorType(const QColor &color);
    static ColorType toColorType(const QPalette &palette);
    ColorType themeType() const;
    ColorType paletteType() const;

    static bool setSingleInstance(const QString &key, SingleScope singleScope = UserScope);
    static void setSingleInstanceInterval(int interval = 3000);
    //D_DECL_DEPRECATED static void setSingelInstanceInterval(int interval = 3000);
    Q_DECL_DEPRECATED static void setSingelInstanceInterval(int interval = 3000);

    // 获取帮助手册目录
    static QStringList userManualPaths(const QString &appName);
    bool hasUserManual() const;

    static bool loadTranslator(const QString &fileName, const QList<QString> &translateDirs, const QList<QLocale> &localeFallback);
    static bool loadTranslator(const QList<QLocale> &localeFallback = QList<QLocale>() << QLocale::system());

public Q_SLOTS:
    //D_DECL_DEPRECATED_X("Plase use setPaletteType") void setThemeType(ColorType themeType);
    Q_DECL_DEPRECATED_X("Plase use setPaletteType") void setThemeType(ColorType themeType);
    void setPaletteType(ColorType paletteType);
    void handleHelpAction();
    static void openUrl(const QString &url);

    DGuiApplicationHelper::SizeMode sizeMode() const;
    void setSizeMode(const DGuiApplicationHelper::SizeMode mode);
    void resetSizeMode();
    static inline bool isCompactMode()
    {
        return instance()->sizeMode() == DGuiApplicationHelper::CompactMode;
    }
};

#endif // DGUIAPPLICATIONHELPER_H
