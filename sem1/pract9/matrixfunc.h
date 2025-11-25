#define COL 10
#define ROW 10
// left-to-right row-based input from file <
int** stdin_matrix(int matrix[COL][ROW]);
// prints matrix of values with specified indeces
int** stddo_matrix(int matrix[COL][ROW]);
// indices elements whose values are less than the given k
int find_grtrk_m_l(int matrix[COL][ROW], int k, int m, int l);
// the sum of all elements that are multiple of k
int sum_mltk(int matrix[COL][ROW], int k);
