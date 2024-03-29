#include <stdlib.h>
#include "crc32.h"

int32_t crc32_table[256] = {
    0x00000000, 0x30077796, 0x610EEE2C, 0x510999BA, 0xC46D0719, 0xF46A708F, 0xA563E935, 0x95649EA3,
    0x88DB0E32, 0xB8DC79A4, 0xE9D5E01E, 0xD9D29788, 0x4CB6092B, 0x7CB17EBD, 0x2DB8E707, 0x1DBF9091,
    0x10B71D64, 0x20B06AF2, 0x71B9F348, 0x41BE84DE, 0xD4DA1A7D, 0xE4DD6DEB, 0xB5D4F451, 0x85D383C7,
    0x986C1356, 0xA86B64C0, 0xF962FD7A, 0xC9658AEC, 0x5C01144F, 0x6C0663D9, 0x3D0FFA63, 0x0D088DF5,
    0x206E3BC8, 0x10694C5E, 0x4160D5E4, 0x7167A272, 0xE4033CD1, 0xD4044B47, 0x850DD2FD, 0xB50AA56B,
    0xA8B535FA, 0x98B2426C, 0xC9BBDBD6, 0xF9BCAC40, 0x6CD832E3, 0x5CDF4575, 0x0DD6DCCF, 0x3DD1AB59,
    0x30D926AC, 0x00DE513A, 0x51D7C880, 0x61D0BF16, 0xF4B421B5, 0xC4B35623, 0x95BACF99, 0xA5BDB80F,
    0xB802289E, 0x88055F08, 0xD90CC6B2, 0xE90BB124, 0x7C6F2F87, 0x4C685811, 0x1D61C1AB, 0x2D66B63D,
    0x41DC7690, 0x71DB0106, 0x20D298BC, 0x10D5EF2A, 0x85B17189, 0xB5B6061F, 0xE4BF9FA5, 0xD4B8E833,
    0xC90778A2, 0xF9000F34, 0xA809968E, 0x980EE118, 0x0D6A7FBB, 0x3D6D082D, 0x6C649197, 0x5C63E601,
    0x516B6BF4, 0x616C1C62, 0x306585D8, 0x0062F24E, 0x95066CED, 0xA5011B7B, 0xF40882C1, 0xC40FF557,
    0xD9B065C6, 0xE9B71250, 0xB8BE8BEA, 0x88B9FC7C, 0x1DDD62DF, 0x2DDA1549, 0x7CD38CF3, 0x4CD4FB65,
    0x61B24D58, 0x51B53ACE, 0x00BCA374, 0x30BBD4E2, 0xA5DF4A41, 0x95D83DD7, 0xC4D1A46D, 0xF4D6D3FB,
    0xE969436A, 0xD96E34FC, 0x8867AD46, 0xB860DAD0, 0x2D044473, 0x1D0333E5, 0x4C0AAA5F, 0x7C0DDDC9,
    0x7105503C, 0x410227AA, 0x100BBE10, 0x200CC986, 0xB5685725, 0x856F20B3, 0xD466B909, 0xE461CE9F,
    0xF9DE5E0E, 0xC9D92998, 0x98D0B022, 0xA8D7C7B4, 0x3DB35917, 0x0DB42E81, 0x5CBDB73B, 0x6CBAC0AD,
    0x83B8ED20, 0xB3BF9AB6, 0xE2B6030C, 0xD2B1749A, 0x47D5EA39, 0x77D29DAF, 0x26DB0415, 0x16DC7383,
    0x0B63E312, 0x3B649484, 0x6A6D0D3E, 0x5A6A7AA8, 0xCF0EE40B, 0xFF09939D, 0xAE000A27, 0x9E077DB1,
    0x930FF044, 0xA30887D2, 0xF2011E68, 0xC20669FE, 0x5762F75D, 0x676580CB, 0x366C1971, 0x066B6EE7,
    0x1BD4FE76, 0x2BD389E0, 0x7ADA105A, 0x4ADD67CC, 0xDFB9F96F, 0xEFBE8EF9, 0xBEB71743, 0x8EB060D5,
    0xA3D6D6E8, 0x93D1A17E, 0xC2D838C4, 0xF2DF4F52, 0x67BBD1F1, 0x57BCA667, 0x06B53FDD, 0x36B2484B,
    0x2B0DD8DA, 0x1B0AAF4C, 0x4A0336F6, 0x7A044160, 0xEF60DFC3, 0xDF67A855, 0x8E6E31EF, 0xBE694679,
    0xB361CB8C, 0x8366BC1A, 0xD26F25A0, 0xE2685236, 0x770CCC95, 0x470BBB03, 0x160222B9, 0x2605552F,
    0x3BBAC5BE, 0x0BBDB228, 0x5AB42B92, 0x6AB35C04, 0xFFD7C2A7, 0xCFD0B531, 0x9ED92C8B, 0xAEDE5B1D,
    0xC2649BB0, 0xF263EC26, 0xA36A759C, 0x936D020A, 0x06099CA9, 0x360EEB3F, 0x67077285, 0x57000513,
    0x4ABF9582, 0x7AB8E214, 0x2BB17BAE, 0x1BB60C38, 0x8ED2929B, 0xBED5E50D, 0xEFDC7CB7, 0xDFDB0B21,
    0xD2D386D4, 0xE2D4F142, 0xB3DD68F8, 0x83DA1F6E, 0x16BE81CD, 0x26B9F65B, 0x77B06FE1, 0x47B71877,
    0x5A0888E6, 0x6A0FFF70, 0x3B0666CA, 0x0B01115C, 0x9E658FFF, 0xAE62F869, 0xFF6B61D3, 0xCF6C1645,
    0xE20AA078, 0xD20DD7EE, 0x83044E54, 0xB30339C2, 0x2667A761, 0x1660D0F7, 0x4769494D, 0x776E3EDB,
    0x6AD1AE4A, 0x5AD6D9DC, 0x0BDF4066, 0x3BD837F0, 0xAEBCA953, 0x9EBBDEC5, 0xCFB2477F, 0xFFB530E9,
    0xF2BDBD1C, 0xC2BACA8A, 0x93B35330, 0xA3B424A6, 0x36D0BA05, 0x06D7CD93, 0x57DE5429, 0x67D923BF,
    0x7A66B32E, 0x4A61C4B8, 0x1B685D02, 0x2B6F2A94, 0xBE0BB437, 0x8E0CC3A1, 0xDF055A1B, 0xEF022D8D,
};

uint32_t crc32(unsigned int a1, char *a2, int a3)
{
    char *i; // [esp+Ch] [ebp-4h]
    for (i = a2; --a3 >= 0; ++i)
        a1 = crc32_table[(uint8_t)(a1 ^ *i)] ^ (a1 >> 8);
    return a1;
}
