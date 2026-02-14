typedef struct {
  size_t rows;
  size_t cols;
  float* data;
} Matrix2D;

// memory methods
Matrix2D *matrix2d_construct_default();
Matrix2D *matrix2d_construct(Matrix2D*, const size_t, const size_t, const float*);
void matrix2d_destruct(Matrix2D*);

// matrix2d methods
// grade "Satisfactory"
_Bool matrix2d_cmp(Matrix2D*, Matrix2D*, _Bool (*cmp)(float, float));
int matrix2d_scanf(Matrix2D*);
void matrix2d_printf(Matrix2D*);
void matrix2d_increment(Matrix2D*);
void matrix2d_decrement(Matrix2D*);
void matrix2d_setter(Matrix2D*);
void matrix2d_random(Matrix2D*);
// grade "Good"
float* matrix2d_get_row(Matrix2D*);
float* matrix2d_get_col(Matrix2D*);
float matrix2d_determinant(Matrix2D*);
// grade "Excellent"
Matrix2D* matrix2d_inverse(Matrix2D*);

// some cmp funcs
_Bool eql(float, float);
_Bool not_eql(float, float);
_Bool grtr(float, float);
_Bool grtr_or_eql(float, float);
_Bool less(float, float);
_Bool less_or_eql(float, float);
