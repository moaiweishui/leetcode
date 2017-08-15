/********************** Solution 1 ************************/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        int f1 = 1, f2 = 2;
	    int next_f;

	    for (int i = 3; i <= n; i++)
	    {
		    next_f = f1 + f2;
		    f1 = f2;
		    f2 = next_f;
	    }
	    return next_f;
        
    }
};

/********************** Solution 2 ************************/
class Solution {
public:
    struct Matrix22
    {
	    int a00;
	    int a01;
	    int a10;
	    int a11;
	    Matrix22(int a00, int a01, int a10, int a11)
		    :a00(a00), a01(a01), a10(a10), a11(a11)
	    {}
    };

    Matrix22 Matrix22Multiply(Matrix22 M1, Matrix22 M2)
    {
	    int m00 = M1.a00*M2.a00 + M1.a01*M2.a10;
	    int m01 = M1.a00*M2.a01 + M1.a01*M2.a11;
	    int m10 = M1.a10*M2.a00 + M1.a11*M2.a10;
	    int m11 = M1.a10*M2.a01 + M1.a11*M2.a11;
	    Matrix22 result(m00, m01, m10, m11);
	    return result;
    }

    Matrix22 Matrix22Power(Matrix22 M, int n)
    {
	    if (n == 1)
		    return M;

	    Matrix22 matrix(0, 0, 0, 0);

	    if (n % 2 == 0)
	    {
		    matrix = Matrix22Power(M, n / 2);
		    matrix = Matrix22Multiply(matrix, matrix);
	    }
	    else if (n % 2 == 1)
	    {
		    matrix = Matrix22Power(M, n / 2);
		    matrix = Matrix22Multiply(matrix, matrix);
		    matrix = Matrix22Multiply(matrix, M);
	    }
	    return matrix;
    }
    
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        Matrix22 M(1, 1, 1, 0);
	    M = Matrix22Power(M, n - 2);
	    return 2 * M.a00 + M.a01;
        
    }
};
