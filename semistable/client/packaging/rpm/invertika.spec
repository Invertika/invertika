Name:		invertika
Version:	r1663
Release:	1%{?dist}
Summary:	A German MMORPG

Group:		Amusements/Games
License:	GPL
URL:		http://invertika.org/
Source0:	http://data.invertika.org/packages/fedora/invertika-%{version}.tbz2
BuildRoot:	%(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

BuildRequires:  cmake
BuildRequires:  enet-devel
BuildRequires:  gettext
BuildRequires:  guichan-devel
BuildRequires:  libcurl-devel
BuildRequires:  libpng-devel
BuildRequires:  libxml2-devel
BuildRequires:  physfs-devel
BuildRequires:  SDL_gfx-devel
BuildRequires:  SDL_image-devel
BuildRequires:  SDL_mixer-devel
BuildRequires:  SDL_net-devel
BuildRequires:  SDL_ttf-devel

Requires:   enet >= 1.2.0, enet < 1.3.0
Requires:   guichan >= 0.8.0
Requires:   physfs >= 1.0.0
Requires:   SDL
Requires:   SDL_gfx
Requires:   SDL_image
Requires:   SDL_mixer
Requires:   SDL_net
Requires:   SDL_ttf
Requires:   zlib >= 1.2.0

%description
Invertika is a German MMORPG.

%prep
%setup -q


%build
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
%find_lang mana

%clean
rm -rf $RPM_BUILD_ROOT

%files -f mana.lang
%{_datadir}/pixmaps/ivk.png
%{_datadir}/applications/invertika.desktop
%{_datadir}/invertika/data/icons/ivk.png
%{_datadir}/invertika/data/fonts/dejavusans.ttf
%{_datadir}/invertika/data/fonts/dejavusans-bold.ttf
%{_datadir}/invertika/data/help/windows.txt
%{_datadir}/invertika/data/help/header.txt
%{_datadir}/invertika/data/help/support.txt
%{_datadir}/invertika/data/help/team.txt
%{_datadir}/invertika/data/help/commands.txt
%{_datadir}/invertika/data/help/index.txt
%{_datadir}/invertika/data/help/skills.txt
%{_datadir}/invertika/data/help/about.txt
%{_datadir}/invertika/data/graphics/sprites/error.xml
%{_datadir}/invertika/data/graphics/sprites/error.png
%{_datadir}/invertika/data/graphics/gui/circle-gray.png
%{_datadir}/invertika/data/graphics/gui/radioin_highlight.png
%{_datadir}/invertika/data/graphics/gui/hscroll_left_highlight.png
%{_datadir}/invertika/data/graphics/gui/hscroll_left_pressed.png
%{_datadir}/invertika/data/graphics/gui/hscroll_right_pressed.png
%{_datadir}/invertika/data/graphics/gui/selection.png
%{_datadir}/invertika/data/graphics/gui/close_button.png
%{_datadir}/invertika/data/graphics/gui/tab.png
%{_datadir}/invertika/data/graphics/gui/bubble.png
%{_datadir}/invertika/data/graphics/gui/window.png
%{_datadir}/invertika/data/graphics/gui/vscroll_down_default.png
%{_datadir}/invertika/data/graphics/gui/window.xml
%{_datadir}/invertika/data/graphics/gui/radioout_highlight.png
%{_datadir}/invertika/data/graphics/gui/speechbubble.xml
%{_datadir}/invertika/data/graphics/gui/vscroll_down_highlight.png
%{_datadir}/invertika/data/graphics/gui/vscroll_highlight.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-red-s.png
%{_datadir}/invertika/data/graphics/gui/sticky_button.png
%{_datadir}/invertika/data/graphics/gui/vscroll_grey.png
%{_datadir}/invertika/data/graphics/gui/colors.xml
%{_datadir}/invertika/data/graphics/gui/vscroll_up_pressed.png
%{_datadir}/invertika/data/graphics/gui/unknown-item.png
%{_datadir}/invertika/data/graphics/gui/circle-green.png
%{_datadir}/invertika/data/graphics/gui/hscroll_right_highlight.png
%{_datadir}/invertika/data/graphics/gui/resize.png
%{_datadir}/invertika/data/graphics/gui/tab_hilight.png
%{_datadir}/invertika/data/graphics/gui/radioout.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-red-l.png
%{_datadir}/invertika/data/graphics/gui/vscroll_up_default.png
%{_datadir}/invertika/data/graphics/gui/vscroll_up_highlight.png
%{_datadir}/invertika/data/graphics/gui/tabselected.png
%{_datadir}/invertika/data/graphics/gui/slider.png
%{_datadir}/invertika/data/graphics/gui/deepbox.png
%{_datadir}/invertika/data/graphics/gui/button.png
%{_datadir}/invertika/data/graphics/gui/hscroll_left_default.png
%{_datadir}/invertika/data/graphics/gui/slider_hilight.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-red-m.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-blue-l.png
%{_datadir}/invertika/data/graphics/gui/mouse.png
%{_datadir}/invertika/data/graphics/gui/buttonhi.png
%{_datadir}/invertika/data/graphics/gui/radioin.png
%{_datadir}/invertika/data/graphics/gui/checkbox.png
%{_datadir}/invertika/data/graphics/gui/item_shortcut_bgr.png
%{_datadir}/invertika/data/graphics/gui/button_disabled.png
%{_datadir}/invertika/data/graphics/gui/hscroll_right_default.png
%{_datadir}/invertika/data/graphics/gui/vscroll_down_pressed.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-blue-m.png
%{_datadir}/invertika/data/graphics/gui/progress-indicator.png
%{_datadir}/invertika/data/graphics/gui/buttonpress.png
%{_datadir}/invertika/data/graphics/gui/target-cursor-blue-s.png
%{_datadir}/invertika/data/graphics/images/login_wallpaper_1280x960.png
%{_datadir}/invertika/data/graphics/images/login_wallpaper_640x480.png
%{_datadir}/invertika/data/graphics/images/login_wallpaper_1600x1200.png
%{_datadir}/invertika/data/graphics/images/login_wallpaper_800x600.png
%{_datadir}/invertika/data/graphics/images/login_wallpaper_1024x768.png
%{_datadir}/invertika/data/graphics/images/error.png
%{_datadir}/invertika/branding.xml
%{_bindir}/invertika

%defattr(-,root,root,-)
%doc



%changelog

