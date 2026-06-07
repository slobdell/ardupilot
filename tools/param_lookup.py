#!/usr/bin/env python3
"""
Look up ArduPilot parameter documentation from local curated docs.

Usage:
    python3 tools/param_lookup.py WVANE_GAIN
    python3 tools/param_lookup.py Q_TILT_RATE_UP
    python3 tools/param_lookup.py wvane          # search by prefix or partial name
"""

import sys
import os
import re

DOCS_DIR = os.path.join(os.path.dirname(__file__), 'parameter_docs')


def parse_frontmatter(text):
    """Extract YAML frontmatter fields as a dict."""
    match = re.match(r'^---\n(.*?)\n---', text, re.DOTALL)
    if not match:
        return {}
    fm = {}
    for line in match.group(1).splitlines():
        if ':' in line:
            key, _, val = line.partition(':')
            fm[key.strip()] = val.strip()
    return fm


def get_body(text):
    """Return content after frontmatter."""
    match = re.match(r'^---\n.*?\n---\n', text, re.DOTALL)
    if match:
        return text[match.end():].strip()
    return text.strip()


def find_param_file(name):
    """Find the .md file for an exact param name."""
    name = name.upper()
    # Determine prefix folder: everything up to (but not including) the last component
    # e.g. WVANE_GAIN -> WVANE, Q_TILT_RATE_UP -> Q, INS_ACCOFFS_X -> INS
    parts = name.split('_')
    # Try progressively shorter prefixes until we find a folder
    for i in range(len(parts), 0, -1):
        prefix = '_'.join(parts[:i])
        folder = os.path.join(DOCS_DIR, prefix)
        if os.path.isdir(folder):
            candidate = os.path.join(folder, f'{name}.md')
            if os.path.exists(candidate):
                return candidate
            # Also check README for group-level lookup
            readme = os.path.join(folder, 'README.md')
            if os.path.exists(readme) and i == len(parts):
                return readme
    return None


def search_params(query):
    """Search for params matching a partial name or prefix."""
    query = query.upper()
    results = []
    for prefix_dir in sorted(os.listdir(DOCS_DIR)):
        if query in prefix_dir:
            folder = os.path.join(DOCS_DIR, prefix_dir)
            if os.path.isdir(folder):
                for f in sorted(os.listdir(folder)):
                    if f.endswith('.md') and f != 'README.md':
                        results.append(f[:-3])  # strip .md
        else:
            folder = os.path.join(DOCS_DIR, prefix_dir)
            if os.path.isdir(folder):
                for f in sorted(os.listdir(folder)):
                    if f.endswith('.md') and f != 'README.md' and query in f.upper():
                        results.append(f[:-3])
    return results


def display_param(path):
    with open(path) as f:
        text = f.read()
    fm = parse_frontmatter(text)
    body = get_body(text)

    name = fm.get('name', os.path.basename(path).replace('.md', ''))
    display_name = fm.get('display_name', '')
    description = fm.get('description', '')
    default = fm.get('default_value', 'n/a')
    units = fm.get('units', '')
    range_ = fm.get('range', '')
    sources = fm.get('source_code_urls', '')

    print(f"\n{'='*60}")
    print(f"  {name}" + (f"  —  {display_name}" if display_name else ''))
    print(f"{'='*60}")
    if description:
        print(f"\n{description}")
    print()
    if default != 'n/a':
        print(f"  Default : {default}" + (f" {units}" if units else ''))
    if range_:
        print(f"  Range   : {range_}" + (f" {units}" if units else ''))
    if sources and sources not in ('null', ''):
        print(f"  Source  : {sources}")

    # Print body, stripping HTML comments and trimming length
    if body:
        clean = re.sub(r'<!--.*?-->', '', body, flags=re.DOTALL).strip()
        # Remove frontmatter-style lines that slipped through
        clean = re.sub(r'\$.*?\$', '', clean)  # strip LaTeX
        lines = [l for l in clean.splitlines() if l.strip()]
        # Print up to 40 lines
        for line in lines[:40]:
            print(line)
        if len(lines) > 40:
            print(f"\n  ... ({len(lines)-40} more lines) — open {path}")
    print()


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(0)

    query = sys.argv[1].upper()

    # Try exact lookup first
    path = find_param_file(query)
    if path:
        display_param(path)
        return

    # Fall back to search
    matches = search_params(query)
    if not matches:
        print(f"No parameter docs found for '{query}'")
        sys.exit(1)

    if len(matches) == 1:
        path = find_param_file(matches[0])
        if path:
            display_param(path)
            return

    print(f"\nFound {len(matches)} parameters matching '{query}':\n")
    for m in matches[:40]:
        # Show one-line description if available
        p = find_param_file(m)
        if p:
            with open(p) as f:
                fm = parse_frontmatter(f.read())
            desc = fm.get('description', '')[:60]
            print(f"  {m:<35} {desc}")
        else:
            print(f"  {m}")
    if len(matches) > 40:
        print(f"  ... and {len(matches)-40} more")
    print(f"\nRun: python3 tools/param_lookup.py <PARAM_NAME> for details")


if __name__ == '__main__':
    main()
