#include <stddef.h> // for size_t

#define EPS 1e-9 // for float comparing

typedef struct {
  size_t rows;
  size_t cols;
  float* data;
} Matrix2D;

// memory methods
Matrix2D *matrix2d_construct_default();
Matrix2D *matrix2d_construct(Matrix2D*, size_t, size_t, const float*);
Matrix2D *matrix2d_construct_copy(Matrix2D*, Matrix2D*);
void matrix2d_destruct(Matrix2D*);

// matrix2d methods
// grade "Satisfactory"
int matrix2d_cmp(Matrix2D*, Matrix2D*);
int matrix2d_wscanf(Matrix2D*);
void matrix2d_wprintf(Matrix2D*);
void matrix2d_increment(Matrix2D*);
void matrix2d_decrement(Matrix2D*);
void matrix2d_setter(Matrix2D*, size_t, size_t, float);
void matrix2d_random(Matrix2D*, float, float);
// grade "Good"
Matrix2D* matrix2d_get_row(Matrix2D*, size_t);
Matrix2D* matrix2d_get_col(Matrix2D*, size_t);
float matrix2d_determinant(Matrix2D*);
float _determinant(const float*, size_t);
// grade "Excellent"
Matrix2D* matrix2d_inverse(Matrix2D*);

// some cmp funcs
_Bool matrix2d_eql(Matrix2D*, Matrix2D*);
_Bool matrix2d_not_eql(Matrix2D*, Matrix2D*);
_Bool matrix2d_grtr(Matrix2D*, Matrix2D*);
_Bool matrix2d_grtr_or_eql(Matrix2D*, Matrix2D*);
_Bool matrix2d_less(Matrix2D*, Matrix2D*);
_Bool matrix2d_less_or_eql(Matrix2D*, Matrix2D*);
