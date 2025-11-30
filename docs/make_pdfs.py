#!/usr/bin/env python3
"""
Generate PDF books for each subfolder in the Universal Maker Sensor Kit documentation.

This script creates separate PDF books for Arduino, ESP32, Pi Pico, and Raspberry Pi
using Sphinx's LaTeX/PDF builder.

Usage:
    uv run make_pdfs.py
"""

import os
import sys
import shutil
import tempfile
from pathlib import Path
from typing import Dict, List
import subprocess


# Define the books to generate
BOOKS = {
    "Arduino": {
        "folder": "02_arduino",
        "title": "Universal Maker Sensor Kit - Arduino Guide",
        "index_file": "arduino.rst",
    },
    "ESP32": {
        "folder": "03_esp32",
        "title": "Universal Maker Sensor Kit - ESP32 Guide",
        "index_file": "esp32.rst",
    },
    "PiPico": {
        "folder": "04_pi_pico",
        "title": "Universal Maker Sensor Kit - Raspberry Pi Pico Guide",
        "index_file": "pi_pico.rst",
    },
    "RaspberryPi": {
        "folder": "05_raspberry_pi",
        "title": "Universal Maker Sensor Kit - Raspberry Pi Guide",
        "index_file": "raspberry_pi.rst",
    },
}


def create_temp_conf(
    source_dir: Path,
    temp_dir: Path,
    book_title: str,
    author: str = "SunFounder"
) -> Path:
    """
    Create a temporary conf.py for PDF generation.

    Args:
        source_dir: Original source directory
        temp_dir: Temporary directory for this build
        book_title: Title for the PDF book
        author: Author name

    Returns:
        Path to the created conf.py
    """
    conf_path = temp_dir / "conf.py"

    conf_content = f'''# Configuration file for PDF generation
import sphinx_rtd_theme
import time

# Project information
project = "{book_title}"
copyright = f'{{time.localtime().tm_year}}, {author}'
author = "{author}"

# Extensions
extensions = [
    'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
]

# Paths
templates_path = ['{source_dir / "_templates"}']
html_static_path = ['{source_dir / "_static"}']
exclude_patterns = []

# LaTeX/PDF output options
latex_engine = 'pdflatex'
latex_elements = {{
    'papersize': 'letterpaper',
    'pointsize': '10pt',
    'preamble': r\'\'\'
\\usepackage{{geometry}}
\\geometry{{margin=1in}}
\'\'\',
    'figure_align': 'htbp',
}}

latex_documents = [
    ('index', f'{{project.replace(" ", "_")}}.tex', project, author, 'manual'),
]

# Theme
html_theme = 'sphinx_rtd_theme'

# Language
language = 'en'
locale_dirs = ['{source_dir / "locale"}/']
gettext_compact = False

# Copy all the custom RST substitutions from the original conf.py
'''

    # Read the original conf.py to get rst_epilog
    original_conf = source_dir / "conf.py"
    if original_conf.exists():
        with open(original_conf, 'r', encoding='utf-8') as f:
            original_content = f.read()

        # Extract rst_epilog
        if 'rst_epilog = """' in original_content:
            start = original_content.find('rst_epilog = """')
            # Find the closing """ with proper handling
            temp_content = original_content[start:]
            first_quote = temp_content.find('"""')
            # Find next """ after the first one
            second_quote = temp_content.find('"""', first_quote + 3)
            if second_quote != -1:
                epilog_section = temp_content[:second_quote + 3]
                conf_content += "\n" + epilog_section + "\n"

    with open(conf_path, 'w', encoding='utf-8') as f:
        f.write(conf_content)

    return conf_path


def copy_dependencies(source_dir: Path, temp_dir: Path, folder: str) -> None:
    """
    Copy necessary files and folders to the temporary directory.

    Args:
        source_dir: Original source directory
        temp_dir: Temporary directory for this build
        folder: Specific subfolder being built
    """
    # Copy the specific platform folder
    platform_src = source_dir / folder
    platform_dst = temp_dir / folder
    if platform_src.exists():
        shutil.copytree(platform_src, platform_dst)

    # Copy shared resources
    shared_folders = ["_static", "_templates", "img"]
    for shared in shared_folders:
        shared_src = source_dir / shared
        shared_dst = temp_dir / shared
        if shared_src.exists():
            shutil.copytree(shared_src, shared_dst, dirs_exist_ok=True)

    # Copy component basics if referenced
    components_src = source_dir / "01_components_basic"
    components_dst = temp_dir / "01_components_basic"
    if components_src.exists():
        shutil.copytree(components_src, components_dst)


def create_index_rst(temp_dir: Path, book_info: Dict, folder: str) -> Path:
    """
    Create a simple index.rst that includes the platform's main file.

    Args:
        temp_dir: Temporary directory for this build
        book_info: Book configuration dictionary
        folder: Specific subfolder being built

    Returns:
        Path to created index.rst
    """
    index_path = temp_dir / "index.rst"

    # Read the original platform index file
    platform_index = temp_dir / folder / book_info["index_file"]

    index_content = f'''{book_info["title"]}
{"=" * len(book_info["title"])}

.. toctree::
   :maxdepth: 3
   :caption: Contents:

   {folder}/{book_info["index_file"].replace(".rst", "")}
'''

    with open(index_path, 'w', encoding='utf-8') as f:
        f.write(index_content)

    return index_path


def build_pdf(
    book_name: str,
    book_info: Dict,
    source_dir: Path,
    output_dir: Path
) -> bool:
    """
    Build a PDF for a specific book.

    Args:
        book_name: Name of the book (e.g., "Arduino")
        book_info: Book configuration dictionary
        source_dir: Original source directory
        output_dir: Output directory for PDFs

    Returns:
        True if successful, False otherwise
    """
    print(f"\n{'=' * 60}")
    print(f"Building PDF for {book_name}...")
    print(f"{'=' * 60}")

    # Create temporary directory
    with tempfile.TemporaryDirectory() as temp_dir_str:
        temp_dir = Path(temp_dir_str)

        # Copy dependencies
        print("Copying files...")
        copy_dependencies(source_dir, temp_dir, book_info["folder"])

        # Create conf.py
        print("Creating configuration...")
        create_temp_conf(source_dir, temp_dir, book_info["title"])

        # Create index.rst
        print("Creating index...")
        create_index_rst(temp_dir, book_info, book_info["folder"])

        # Build LaTeX
        print("Building LaTeX...")
        latex_dir = temp_dir / "_build" / "latex"
        result = subprocess.run(
            [
                "sphinx-build",
                "-b", "latex",
                "-d", str(temp_dir / "_build" / "doctrees"),
                str(temp_dir),
                str(latex_dir)
            ],
            capture_output=True,
            text=True
        )

        if result.returncode != 0:
            print(f"ERROR building LaTeX for {book_name}:")
            print(result.stderr)
            return False

        # Build PDF with pdflatex
        print("Building PDF...")
        pdf_file = list(latex_dir.glob("*.tex"))
        if not pdf_file:
            print(f"ERROR: No .tex file found for {book_name}")
            return False

        # Run pdflatex (run twice for proper references)
        for i in range(2):
            print(f"Running pdflatex (pass {i+1}/2)...")
            result = subprocess.run(
                ["pdflatex", "-interaction=nonstopmode", pdf_file[0].name],
                cwd=latex_dir,
                capture_output=True,
                text=True
            )
            if result.returncode != 0 and i == 1:  # Only fail on second pass
                print(f"WARNING: pdflatex returned non-zero exit code for {book_name}")
                # Don't fail completely, PDF might still be generated

        # Copy PDF to output directory
        pdf_files = list(latex_dir.glob("*.pdf"))
        if pdf_files:
            output_file = output_dir / f"{book_name}_Guide.pdf"
            shutil.copy2(pdf_files[0], output_file)
            print(f"✓ Successfully created: {output_file}")
            return True
        else:
            print(f"ERROR: No PDF generated for {book_name}")
            return False


def main():
    """Main function to generate all PDFs."""
    # Get paths
    script_dir = Path(__file__).parent
    source_dir = script_dir / "source"
    output_dir = script_dir / "pdfs"

    # Create output directory
    output_dir.mkdir(exist_ok=True)

    print("Universal Maker Sensor Kit - PDF Generator")
    print("=" * 60)
    print(f"Source directory: {source_dir}")
    print(f"Output directory: {output_dir}")

    # Check if source directory exists
    if not source_dir.exists():
        print(f"ERROR: Source directory not found: {source_dir}")
        sys.exit(1)

    # Check if pdflatex is available
    try:
        subprocess.run(
            ["pdflatex", "--version"],
            capture_output=True,
            check=True
        )
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("\nERROR: pdflatex not found!")
        print("Please install a LaTeX distribution:")
        print("  - macOS: brew install --cask mactex-no-gui")
        print("  - Ubuntu/Debian: sudo apt-get install texlive-latex-extra")
        print("  - Windows: Install MiKTeX from https://miktex.org/")
        sys.exit(1)

    # Build each book
    results = {}
    for book_name, book_info in BOOKS.items():
        success = build_pdf(book_name, book_info, source_dir, output_dir)
        results[book_name] = success

    # Print summary
    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    for book_name, success in results.items():
        status = "✓ SUCCESS" if success else "✗ FAILED"
        print(f"{book_name:20s} {status}")

    print(f"\nPDFs saved to: {output_dir}")

    # Exit with error if any failed
    if not all(results.values()):
        sys.exit(1)


if __name__ == "__main__":
    main()
