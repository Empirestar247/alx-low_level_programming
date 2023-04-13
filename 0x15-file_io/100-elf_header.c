#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define EI_NIDENT 16

typedef struct elf_header
{
	unsigned char e_ident[EI_NIDENT];
	unsigned short e_type;
	unsigned short e_machine;
	unsigned int e_version;
	unsigned long e_entry;
	unsigned long e_phoff;
	unsigned long e_shoff;
	unsigned int e_flags;
	unsigned short e_ehsize;
	unsigned short e_phentsize;
	unsigned short e_phnum;
	unsigned short e_shentsize;
	unsigned short e_shnum;
	unsigned short e_shstrndx;
} Elf64_Ehdr;

void print_error_message(const char *message)
{
	while (*message)
	{
		write(2, message, 1);
		message++;
	}
}
void print_hex(unsigned char *buffer, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
	{
		printf("%02x", buffer[i]);
	}
	printf(" ");
}

void print_elf_header(Elf64_Ehdr *header)
{
	printf("Magic:");
	print_hex(header->e_ident, EI_NIDENT);
	printf("\n");
	printf("Class:");
	switch (header->e_ident[4])
	{
		case 1:
			printf("ELF32\n");
			break;
		case 2:
			printf("ELF64\n");
			break;
	}

	printf("Data:");
	switch (header->e_ident[5])
	{
		case 1:
			printf("little endian\n");
			break;
		case 2:
			printf("big endian\n");
			break;
	}

	printf("Version:%u\n", header->e_version);
	printf("OS/ABI:%u\n", header->e_ident[7]);
	printf("ABI Version:%u\n", header->e_ident[8]);
	printf("Type:");
	switch (header->e_type)
	{
            case 1:
                    printf("REL (Relocatable file)\n");
                    break;
            case 2:
                    printf("EXEC (Executable file)\n");
                    break;
            case 3:
                    printf("DYN (Shared object file)\n");
                    break;
            default:
                    printf("%hu\n", header->e_type);
	}

	printf("Entry point address:%#lx\n", header->e_entry);
	printf("Start of program headers:%1u (bytes into file)\n", header->e_phoff);
	printf("Start of section headers:%lu (bytes into file)\n", header->e_shoff);
	printf("Flags:%u\n", header->e_flags);
	printf("Size of this header:%1u (bytes)\n", header->e_ehsize);
	printf("Size of program headers:%1u (bytes)\n", header->e_phentsize);
	printf("Number of program headers:%u\n", header->
			printf("Size of section headers:%1u (bytes)\n", header->e_shentsize);
			printf("Number of section headers:%u\n", header->e_shnum);
			printf("Section header string table index:%u\n", header->e_shstrndx);
			}
			Elf64_Ehdr *read_elf_header(int fd)
			{
			Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));

			if (!header)
			{
			print_error_message("Error: Unable to allocate memory\n");
			exit(98);
			}

			ssize_t bytes_read = read(fd, header, sizeof(Elf64_Ehdr));
			if (bytes_read != sizeof(Elf64_Ehdr))
			{
			print_error_message("Error: Unable to read ELF header\n");
			exit(98);
			}

			return (header);

			}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		 print_error_message("Error: Invalid number of arguments\n");
        exit(97);
	}

	Elf64_Ehdr *header = read_elf_header(fd);
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error_message("Error: Unable to open file\n");
		exit(98);
	}
	header = read_elf_header(fd);

	if (header->e_ident[0] != 0x7f || header->e_ident[1] != 'E' || header->e_ident[2] != 'L' || header->e_ident[3] != 'F')
	{
		print_error_message("Error: Not an ELF file\n");
		exit(98);
	}
	print_elf_header(header);

	free(header);
	close(fd);
	return (0);
}
