/* See LICENSE file for copyright and license details. */

/* Constants */
#define BROWSER "brave"
#define TERMINAL "run_alacritty"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 17;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10", "FontAwesome:size=10", "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true" };

static char normfgcolor[]                = "#ebdbb2";
static char normbgcolor[]                = "#282828";
static char normbordercolor[]            = "#3c3836";
static char selfgcolor[]                 = "#fbf1c7";
static char selbgcolor[]                 = "#d65d0e";
static char selbordercolor[]             = "#d65d0e";
static char *colors[][3] = {
/*               fg           bg           border   */
[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };*/
static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run" };
static const char *termcmd[]  = { "run_alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h> // this is to support XF86 keys

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,			XK_grave,  spawn,	   {.v = (const char*[]){ "dmenuunicode", NULL } } },
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
        { MODKEY|ShiftMask,		XK_p,		spawn,		{.v = (const char*[]){ "passmenu", NULL } } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, togglescratch,  {.v = scratchpadcmd } },
        { MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,      zoom,           {0} },
    /* { MODKEY,                       XK_Tab,    view,           {0} }, */
	{ MODKEY|ShiftMask,             XK_x,      killclient,     {0} },
	{ MODKEY,			XK_w,      spawn,          {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // tile
	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[1]} }, // monocle
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[2]} }, // spiral
	{ MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[3]} }, // dwindle
        { MODKEY|ShiftMask,		XK_f,	   setlayout,	   {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_r,      togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Left,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Left,  tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_Right, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Right, tagmon,         {.i = +1 } },
	// { MODKEY|ShiftMask,             XK_h,      layoutscroll,   {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Tab,      layoutscroll,   {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,           quit,      {0} },
        { 0,				XK_Print,	spawn,	   SHCMD("maimshot") },
        { MODKEY,			XK_m,		spawn,     {.v = (const char*[]){ TERMINAL, "-e", "rmptui", NULL } } },
	{ MODKEY,			XK_Escape,	spawn,		{.v = (const char*[]){ "sysact", NULL } } },
	{ MODKEY|ShiftMask,		XK_Escape,	spawn,		{.v = (const char*[]){ "sysact", NULL } } },


        // Audio related keymaps
	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t;kill -44 $(pidof dwmblocks") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer -i 2;kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer -d 2;kill -44 $(pidof dwmblocks)") },
        { 0, XF86XK_AudioPrev,		spawn,		{.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ 0, XF86XK_AudioNext,		spawn,		{.v = (const char*[]){ "mpc",  "next", NULL } } },
	{ 0, XF86XK_AudioPause,		spawn,		{.v = (const char*[]){ "mpc", "pause", NULL } } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = (const char*[]){ "mpc", "play", NULL } } },
	{ 0, XF86XK_AudioStop,		spawn,		{.v = (const char*[]){ "mpc", "stop", NULL } } },
	{ 0, XF86XK_AudioRewind,	spawn,		{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ 0, XF86XK_AudioForward,	spawn,		{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
        { 0, XF86XK_MonBrightnessUp,	spawn,		{.v = (const char*[]){ "backlight_control", "+15", NULL } } },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		{.v = (const char*[]){ "backlight_control", "-15", NULL } } },

        { MODKEY,			XK_p,		spawn,		{.v = (const char*[]){ "mpc", "toggle", NULL } } },
        { MODKEY|ShiftMask,		XK_comma,	spawn,		{.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		{.v = (const char*[]){ "mpc", "next", NULL } } },
	{ MODKEY,                       XK_comma,	spawn,		{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ MODKEY,               	XK_period,	spawn,		{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },

        { MODKEY,			XK_F9,		spawn,		{.v = (const char*[]){ "mounter", NULL } } },
        { MODKEY,			XK_F10,		spawn,		{.v = (const char*[]){ "unmounter", NULL } } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

