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
unsigned char rgbled_field_get_red(rgbled*);
unsigned char rgbled_field_get_green(rgbled*);
unsigned char rgbled_field_get_blue(rgbled*);
unsigned char rgbled_field_get_bright(rgbled*);
unsigned int rgbled_field_get_temp(rgbled*);
unsigned char rgbled_field_get_type(rgbled*);
unsigned char rgbled_field_get_mode(rgbled*);

// some functions to set a specific value from rgbled structure
void rgbled_field_set_red(rgbled*, unsigned char);
void rgbled_field_set_green(rgbled*, unsigned char);
void rgbled_field_set_blue(rgbled*, unsigned char);
void rgbled_field_set_bright(rgbled*, unsigned char);
void rgbled_field_set_temp(rgbled*, unsigned int);
void rgbled_field_set_type(rgbled*, unsigned char);
void rgbled_field_set_mode(rgbled*, unsigned char);
