<p>
  <img src="xpdf-qt/xpdf-icon.svg" alt="xpdf26 Logo" width="128" />
</p>

# xpdf26

**xpdf26** is a customized, modernized fork of the classic Xpdf PDF viewer.

It isolates the namespace to prevent system conflicts and introduces a new pure black Qt UI, which departs from the traditional white theme of Xpdf.

## Features and Changes

* **Isolated Installation:** All binaries, tools, and man pages transitioned to `xpdf26` allowing it to be installed alongside the standard system `xpdf` without conflicts.
* **Pure Black UI:** Replaces entirely the traditional default white theme with a sleek, hardcoded black and red theme for modern OS aesthetics.
* **Modernized Scrollbars:** Modernized the legacy Qt scrollbars, replacing them with a minimal, track-style design.
* **Improved compile environment:** Updated and modernized compiler configuration, with redundant and deprecated sections transitioned to modern syntax.

## Dependencies

To build xpdf26:
* CMake (4.4.5)
* Make
* Qt6
* FreeType 2
* Fontconfig

## Prepare, Compile and Install

Like its predecessor, xpdf26 uses CMake.

To compile and install xpdf26 from the source code:

```bash
# Clone the repository
> git clone https://www.github.com/fpucore/xpdf26.git

> cd xpdf26

# Create the build directory
> mkdir build

> cd build

# Configure the build system
> cmake -DCMAKE_BUILD_TYPE=Release ..

# Compile
> make

# Install
> sudo make install
```

## Credits & Licensing

* **Core:** Based on Xpdf 4.06. Copyright 1996-2025 Glyph & Cog, LLC.
* **xpdf26:** Copyright 2026 Chris McGimpsey-Jones <chrisjones.unixmen@gmail.com>
* **License:** GNU General Public License Version 3 (GPLv3)
* **Icon:** Application icon/logo provided under the Pixabay Content License.