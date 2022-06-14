#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <wm.h>
#include <stddef.h>

static const desktop_t desktops[] = {
  //  { "1 " }, { "2 " }, { "3 " }, { "4 " }, { "5" }, { NULL }
    {" "}, {" "}, {" "}, {" "}, {""}, { NULL }
};

static const config_t configs[] = {
    /* name                     value*/
    { "border_width",           "2" },
    { "window_gap",             "2" },
    { "split_ratio",            "0.52" },
    { "borderless_monocle",     "true" },
    { "gapless_monocle",        "true" },
    { "focus_follows_pointer",  "true" },
    { "active_border_color",    "\\#e6e1cf" },
    { NULL }
};

static const char* autostart_script = "/home/inu/.config/bspwm/autostart.sh";

static const char* bar_script = "/home/inu/.config/polybar/launch.sh";

static const window_rule_t window_rules[] = {
    //name      desktop     mode        follow
    { "Gimp",      "^8",      "floating", "on" },
    { "Chromium",  "^2",      "tiling",   "off" },
    { NULL }
};

#endif