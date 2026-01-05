import sys
from pathlib import Path


def generate(input_path: Path):
    text = input_path.read_text(encoding="utf-8")

    utf16le_path = input_path.with_name(input_path.name.split("_utf8.txt")[0]+"_utf16le.txt")
    utf16le_path.write_bytes(
        b"\xff\xfe" + text.encode("utf-16le")
    )

    utf16be_path = input_path.with_name(input_path.name.split("_utf8.txt")[0]+"_utf16be.txt")
    utf16be_path.write_bytes(
        b"\xfe\xff" + text.encode("utf-16be")
    )

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} input_utf8.txt")
        sys.exit(1)

    generate(Path(sys.argv[1]).resolve())