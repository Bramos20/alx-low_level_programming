#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_magic_numbers(unsigned char *magic_numbers);
void print_class_info(unsigned char class);
void print_data_info(unsigned char data);
void print_version_info(unsigned char version);
void print_abi_info(unsigned char osabi);
void print_osabi_info(unsigned char osabi);
void print_type_info(unsigned int type);
void print_entry_point(unsigned long int entry);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        return 98;
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        dprintf(STDERR_FILENO, "Error: Unable to read ELF header from file %s\n", argv[1]);
        close(fd);
        return 98;
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
        close(fd);
        return 98;
    }

    printf("ELF Header:\n");
    print_magic_numbers(header.e_ident);
    print_class_info(header.e_ident[EI_CLASS]);
    print_data_info(header.e_ident[EI_DATA]);
    print_version_info(header.e_ident[EI_VERSION]);
    print_abi_info(header.e_ident[EI_OSABI]);
    print_osabi_info(header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    print_type_info(header.e_type);
    print_entry_point(header.e_entry);

    close(fd);
    return 0;
}

void print_magic_numbers(unsigned char *magic_numbers)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", magic_numbers[i]);
        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_class_info(unsigned char class)
{
    printf("Class:   ");
    switch (class)
    {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", class); break;
    }
}

void print_data_info(unsigned char data)
{
    printf("Data:    ");
    switch (data)
    {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", data); break;
    }
}

void print_version_info(unsigned char version)
{
    printf("Version: %d", version);
    switch (version)
    {
        case EV_NONE: printf(" (invalid version)\n"); break;
        case EV_CURRENT: printf(" (current)\n"); break;
        default: printf("\n"); break;
    }
}

void print_abi_info(unsigned char osabi)
{
    printf("OS/ABI:  ");
    switch (osabi)
    {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        default: printf("<unknown: %x>\n", osabi); break;
    }
}

void print_osabi_info(unsigned char osabi)
{
    printf("ABI:     ");
    switch (osabi)
    {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        default: printf("<unknown: %x>\n", osabi); break;
    }
}

void print_type_info(unsigned int type)
{
    printf("Type:    ");
    switch (type)
    {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", type); break;
    }
}

void print_entry_point(unsigned long int entry)
{
    printf("Entry point address: 0x%lx\n", entry);
}
