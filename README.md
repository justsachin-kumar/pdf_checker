# PDF Signature Checker in C

This is a simple C program that checks whether a file is a PDF by reading its signature (magic number) from the first 4 bytes. The program uses the CS50 library, but can be modified to run on systems without it.

## 📁 File Structure

- `check_pdf.c` – C source code to check if a file is a PDF.

## 📦 Dependencies

- CS50 Library (optional)
  - If not available, change `string` to `char *` in the `main()` function argument:
    ```c
    int main(int argc, string argv[]) -> int main(int argc, char *argv[])
    ```

## 🔧 Compilation

To compile with `gcc`:

```bash
gcc check_pdf.c -o check_pdf
```

If you're using the CS50 library:

```bash
clang -o check_pdf check_pdf.c -lcs50
```

## ▶️ Usage

Run the program with a filename as an argument:

```bash
./check_pdf <filename>
```

### Example

```bash
./check_pdf sample.pdf
```

## ✅ What It Does

- Reads the first 4 bytes of the input file.
- Compares them against the PDF signature: `0x25 0x50 0x44 0x46` (which is `%PDF`).
- Prints whether the file is a PDF or not.

## 📌 Notes

- The file is only opened and read — no modifications are made.
- The file is closed after reading.
- If the file isn't found or readable, it may cause a segmentation fault (consider adding `NULL` check for `fopen()` in future versions).

