#include "dguiapplicationhelper.h"

DGuiApplicationHelper::DGuiApplicationHelper()
{

}

DPlatformTheme *DGuiApplicationHelper::systemTheme() const
{
    DPlatformTheme *theme = new DPlatformTheme();
    return theme;
}

DPlatformTheme *DGuiApplicationHelper::applicationTheme() const
{
    DPlatformTheme *theme = new DPlatformTheme();
    return theme;
}

DPalette DGuiApplicationHelper::applicationPalette() const
{
    return DPalette();
}

DPalette DGuiApplicationHelper::applicationPalette(ColorType paletteType) const
{
    return DPalette();
}

DGuiApplicationHelper::ColorType DGuiApplicationHelper::themeType() const
{
    return DGuiApplicationHelper::ColorType::UnknownType;
}

DGuiApplicationHelper::ColorType DGuiApplicationHelper::paletteType() const
{
    return DGuiApplicationHelper::ColorType::UnknownType;
}

bool DGuiApplicationHelper::hasUserManual() const
{
    return false;
}

void DGuiApplicationHelper::setPaletteType(DGuiApplicationHelper::ColorType paletteType)
{

}

void DGuiApplicationHelper::handleHelpAction()
{

}

DGuiApplicationHelper::SizeMode DGuiApplicationHelper::sizeMode() const
{

}

void DGuiApplicationHelper::setSizeMode(const DGuiApplicationHelper::SizeMode mode)
{

}

void DGuiApplicationHelper::resetSizeMode()
{

}
