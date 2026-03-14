# Bit manipulations

There're two different realizations (I prefer the last one):
1. Bitwise fields struct (implemented in `bitrgbled_field.h` and `bitrgbled_field.c`)
2. Bitwise operations only (implemented in `bitrgbled_ops.h` and `bitrgbled_ops.c`)

## Bitwise fields struct (grade "Satisfactory")

It just needs to make struct bitwise field like and some functions to set or get their values.  
Smth like that:  
```
typedef struct {
    unsigned int x : 4;
    unsigned int y : 4;
    unsigned int state : 1;
    unsigned int flag : 1;
} bitstruct;
```  
It's so simple that constructions like `bitstruct->x = 10` can be used.  

## Alignment functions (grade "Good")

The lecture only has `_Alignas` and `_Alignof` functions.  
- `_Alignas` = `alignas` - set minimal margin, but not paddings in struct, only the start of it.
- `_Alignof` = `alignof` - show align.  
    
There're other ways to change aligns the lecture hasn't:  
- `#pragma pack` - more advanced tool, can change margins and paddings, set it and return 'em to their original state.  
- `__attribute__((packed))` - equivalent `#pragma pack(1)` - pack with no aligngs. This compilator's key word is more advanced. It allows to change functions attributes. `packed` is just one of them. You can also do it like: `__attribute__((packed, aligned(2)))`, its equivalent is `#pragma pack(2)`. Without attribute `packed` it will work like `_Alignas`. For example, `__attribute__((aligned(4)))` === `alignas(4)`  
  
It's necessary to demonstrate how does alignment work. For example, `alignof` and `sizeof` struct before and after using alignment functions that it's easy to understand the key concept.  

## Bitwise operations only (grade "Excellent")

Create a struct w/ only one element that can contain all the values has to. Otherwods, sum of `sizeof` every element is needed to store <= `sizeof struct->data`. Thus, for **bitstruct** this structure will looks like that:  
```
typedef struct {
    unsigned short data;
} bitops;
```  
  
**Explanation**: `sizeof(short)` in 64-bit system >= 16 bits, `sizeof(bitstruct)` equals 10 bits. It's obvious that 6 bits won't be used. But this is only way exists to store 10 bits in one variable. 'Cuz there's no type with 10 bits, only `char` with 8 bits and `int` with 16 bits.  
  
Unlike bitwise fields structure, it's so hard that only bitwise operations (and masks) can be used.  
It also needs to define **constants** for offsets, sizes (in bits) and masks for every value.  

## Variant 2 

It's necessary to create `rgbled` structure with these fields:
1. red channel
2. green channel
3. blue channel
4. brightness (levels)
5. temperature (in Kelvins)
6. type of control module
7. mode (steady, flashing, fading)  
  
Example of realization:  
```
typedef struct {
    unsigned int red : 8;
    unsigned int green : 8;
    unsigned int blue : 8;
    unsigned int bright : 8;
    unsigned int temp : 14;
    unsigned int type : 2;
    unsigned int mode : 2;
} rgbled;
```
