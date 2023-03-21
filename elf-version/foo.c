#include <elf.h>

#define PRODUCT_VERSION "1.2.3"

//This static exists to embed the version into libfoo.so
//It can be retrieved using what(1) or strings + grep
//$ strings Library.so | grep "@(#)"
//Format is from SCCS https://en.wikipedia.org/wiki/Source_Code_Control_System
static char sccsid[] __attribute__((used)) = "@(#)Version " PRODUCT_VERSION;

// This creates a new note in the ELF header
// https://man7.org/linux/man-pages/man5/elf.5.html
//$ readelf -Wn Library.so
#define NOTE_SECTION ".note.foo.version"

//Elf64_Nhdr + desc
struct version_note {
    Elf64_Word	namesz;
    Elf64_Word	descsz;
    Elf64_Word	type;
    char    desc[sizeof(PRODUCT_VERSION)];
};

__attribute__((used, section(NOTE_SECTION), aligned(4)))
static const struct version_note version_header = {
    .namesz = 0,
    .descsz = sizeof(PRODUCT_VERSION),
    .type = NT_VERSION,
    .desc = PRODUCT_VERSION
};


// version export
const char* version()
{
    return PRODUCT_VERSION;
}