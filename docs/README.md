# Universal Maker Sensor Kit Documentation

This directory contains the documentation for the Universal Maker Sensor Kit, organized by platform (Arduino, ESP32, Raspberry Pi Pico, and Raspberry Pi).

## Generating PDF Books

The `make_pdfs.py` script generates separate PDF books for each platform.

### Prerequisites

1. **LaTeX Distribution** (required for PDF generation):
   - **macOS**: `brew install --cask mactex-no-gui` or `brew install --cask basictex`
   - **Ubuntu/Debian**: `sudo apt-get install texlive-latex-extra texlive-fonts-recommended`
   - **Windows**: Install [MiKTeX](https://miktex.org/)

2. **Python dependencies**: Managed by `uv` (already configured in `pyproject.toml`)

### Usage

#### Option 1: Run directly with uv
```bash
uv run python make_pdfs.py
```

#### Option 2: Run as installed script
```bash
uv run make-pdfs
```

#### Option 3: Run directly with Python (after installing dependencies)
```bash
python make_pdfs.py
```

### Output

The script will create a `pdfs/` directory containing four PDF books:
- `Arduino_Guide.pdf` - Complete Arduino tutorials
- `ESP32_Guide.pdf` - Complete ESP32 tutorials
- `PiPico_Guide.pdf` - Complete Raspberry Pi Pico tutorials
- `RaspberryPi_Guide.pdf` - Complete Raspberry Pi tutorials

### How It Works

The script:
1. Creates temporary build directories for each platform
2. Copies the relevant documentation files and shared resources
3. Generates a custom Sphinx configuration for PDF output
4. Builds LaTeX files using Sphinx
5. Compiles PDFs using pdflatex
6. Saves the final PDFs to the `pdfs/` directory

### Troubleshooting

**Error: "pdflatex not found"**
- Install a LaTeX distribution (see Prerequisites above)
- Ensure `pdflatex` is in your PATH

**Error: "Missing .sty file"**
- Install additional LaTeX packages:
  - macOS: The full MacTeX installation includes all packages
  - Ubuntu/Debian: `sudo apt-get install texlive-latex-extra`

**Build warnings**
- Some warnings during PDF generation are normal (missing references, overfull boxes)
- The script runs pdflatex twice to resolve cross-references

## Building HTML Documentation

To build the standard HTML documentation:

```bash
make html
```

The HTML files will be in `source/_build/html/`.
