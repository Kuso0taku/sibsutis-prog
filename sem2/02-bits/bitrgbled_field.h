typedef struct {
    unsigned int red : 8;
    unsigned int green : 8;
    unsigned int blue : 8;
    unsigned int bright : 8;
    unsigned int temp : 14;
    unsigned int type : 2;
    unsigned int mode : 2;
} rgbled;

rgbled *rgbled_field_create(void); // malloc new structure
void rgbled_field_free(rgbled*); // free memory

// some functions to get a specific value from rgbled structure
unsigned char rgbled_field_get_red(void);
unsigned char rgbled_field_get_green(void);
unsigned char rgbled_field_get_blue(void);
unsigned char rgbled_field_get_bright(void);
unsigned int rgbled_field_get_temp(void);
unsigned char rgbled_field_get_type(void);
unsigned char rgbled_field_get_mode(void);

// some functions to set a specific value from rgbled structure
void rgbled_field_set_red(unsigned char);
void rgbled_field_set_green(unsigned char);
void rgbled_field_set_blue(unsigned char);
void rgbled_field_set_bright(unsigned char);
void rgbled_field_set_temp(unsigned int);
void rgbled_field_set_type(unsigned char);
void rgbled_field_set_mode(unsigned char);
