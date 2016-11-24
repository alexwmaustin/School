
package question.pkg1;
import java.math.*;
import java.util.*;

public class Matrix{
    

	private int[][]  matrixData;	// integer array to store integer data
	private int  rowsNum;	// number of rows
	private int  colsNum;	// number of columns
	
	public Matrix( int row, int col ) //constructor1
	{   
            
            colsNum = col;
            rowsNum = row;
            
                if(row <= 0)
                {
                    rowsNum = 3;
                }
                if(col <= 0)
                {
                    colsNum = 3;
                }
                matrixData = new int[rowsNum][colsNum];
                
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<col;j++)
                    {
                        matrixData[i][j]=0;
                    }
                }    
	}
                
	
	public Matrix( int[][] table) // constructor2
	{	
		/* constructs a matrix out of the two dimensional array table, 
		   with the same number of rows, columns, and the same element in each
		 position as array table. */	
		
		rowsNum = table.length;
		colsNum = table[0].length;
		matrixData = new int[rowsNum][colsNum]; // allocates memory for the 2D array
		//loop to fill the array with values:
		for (int i=0; i<rowsNum; i++)
			for(int j=0; j<colsNum; j++)
				matrixData[i][j] = table[i][j];
	
	}//end second constructor 
	
	public int getRows(){return rowsNum;}
        public int getCol(){return colsNum;}   
        public int[][] getMatrixData(){return matrixData;}
        
	public int getElement(int i, int j) throws IndexOutOfBoundsException
	{ 	
		/* if i and j are valid indices of this matrix, 
		   then the element on row i and column j of this matrix
		   is returned; otherwise it throws an exception with message "Invalid indexes".*/
		
		if  ( i < rowsNum && j < colsNum ) {
			return matrixData[i][j];
		}
		else {
			throw new IndexOutOfBoundsException("Invalid indexes.");
		}
	  
	}//end getElement
        public boolean setElement(int x, int i, int j)
        {
            if  ( i < rowsNum && j < colsNum ) 
            {
		matrixData[i][j] = x;
                return true;
            }
            else
            {
                return false;
            }
        }
        
	public Matrix copy()
	{ /* returns a deep copy of this Matrix */
            return new Matrix(this.matrixData);
	}//end copy

        public void addTo( Matrix m ) throws ArithmeticException
	{
		/*adds Matrix m to this Matrix; it throws an exception message "Invalid operation"
		  if the matrix addition is not defined*/

		if ( m.rowsNum==rowsNum&&m.colsNum==colsNum) {
			for (int i=0; i<rowsNum; i++)
                            for(int j=0; j<colsNum; j++)
				matrixData[i][j] += m.matrixData[i][j];
		}
		else {
			throw new ArithmeticException("Invalid operation");
		}

	}
	public Matrix subMatrix(int i, int j) throws ArithmeticException
        {
            if( i < rowsNum && j < colsNum ) 
            {
			Matrix subM = new Matrix(i+1,j+1);
                        for (int x=0; x <=i; x++)
                            for(int y=0; y <=j; y++)
                            {
                                System.out.println(x+""+y);
                                subM.matrixData[x][y]=this.matrixData[x][y];
                            }
                        return subM;
            }
            else 
            {
			throw new ArithmeticException("Submatrix not defined.");
            }
        }
        
        public boolean isUpperTr()
        {
            for (int i = 1; i < rowsNum; ++i) // rows
                for (int j = 0; j < i; ++j)
                    if(matrixData[i][j] != 0)
                        return false;
            return true;
        }
        
        public static Matrix sum(Matrix[] matArray)throws ArithmeticException
        {
            Matrix addMatrix = new Matrix(2,2);
            
            for(int i =0;i < matArray.length;i++)
                addMatrix.addTo(matArray[i]);
            
            return addMatrix;
            
        }
        
	public String toString(  )
	{
		/* returns a string representing the matrix, 
		   with each row on a line, and the elements in each row being separated by 2 blank spaces. */
		
		String output = new String(); // creates an empty string
        	for(int i = 0; i < rowsNum; i++){
                    for(int j = 0; j < colsNum; j++){
        		output += matrixData[i][j] + "  ";
        		}
        	output += "\n";
        	}
       		 return output;

	}
        
        
    
        
    
    
    
    public static void main(String[] args) 
    {
        /******** parameters are here ************/
    /****     Test Matrix      *****/    
    // for constructor1
        int invalid_row1 = -1, invalid_col1 = -2;
        int invalid_row2 = 1,  invalid_col2 = 0;        
        int valid_row = 3,     valid_col = 4;
    // for constructor2
        int[][] data = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    // for getElement, this method gets elements from 'data' matrix above
        int getvalid_row = 1, getvalid_col = 3;
        int getinvalid_row = 10, getinvalid_col = 2;
    // for subMatrix, the submatrix is obtained from 'data' matrix above
        int subvalid_row = 3, subvalid_col = 3;
        int subinvalid_row = 3, subinvalid_col = 6;
    // for isUpper, matrix 'Upper1' is uppertriangular, and matrix 'notUpper1', 'notUpper2' are not    
        int[][] Upper1 = {{1,4,5},{0,9,8},{0,0,7},{0,0,0}};
        int[][] notUpper1 = {{1,4,1,4},{0,7,6,5},{0,1,4,9}};
        int[][] notUpper2 = {{1,4,1},{1,9,1},{0,2,4}}; // not a square matrix
    // foe addTo    
        int[][] add_to_data = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match
        int[][] add_to_above = {{1,0,-1}, {2,1,0}, {2,2,2},{0,-1,0}}; // add to 'add_to_data' matrix
    // for sum()
        int size=4;
        Matrix[] arr = new Matrix[size];
        for(int i=0; i<size; i++)
            arr[i]=new Matrix(2,3);
        arr[2]= new Matrix(3,3);     // invalid, due to dimension do not match
        
        Matrix[] arr2 = new Matrix[3];  // valid, can change the matrices here
        int[][] temp1={{1,-1,2}, {1,0,-2}};
        int[][] temp2={{1,0,1}, {0,1,2}};
        int[][] temp3={{0,3,-1}, {0,0,1}};
        arr2[0] = new Matrix(temp1);
        arr2[1] = new Matrix(temp2);
        arr2[2] = new Matrix(temp3);
    // for setElement, operates on 'data' matrix
        int value = 100;
        int setvalid_row = 0, setvalid_col = 0;
        int setinvalid_row = 10, setinvalid_col = 10;
    // for copy, copy data matrix to a new matrix, and modify the new matrix will not change data matrix
        Matrix origin = new Matrix(valid_row,valid_col); // create an original matrix
        Matrix copied = origin.copy();  // make a copy
        copied.setElement(50,0,0);   // modify the copied matrix
        
    ////////////////////////////////////////////////////////////////////////
        
    /****     Test LowerTriangularMatrix      *****/
    // for constructor1    
    int size_invalid = -5, size_valid = 4;
    // for constructor2 
    int[][] con2_11 = {{1,2,3,4,5},{0,6,7,8,9},{0,0,10,11,12},{0,0,0,13,14},{0,0,0,0,15}};
    int[][] con2_21 = {{10,9,8,7},{0,6,5,4},{0,0,3,2},{0,0,0,1}};
    int[][] notupp = {{1,0,0},{2,2,0},{3,3,3}};
    Matrix con2_1 = new Matrix(con2_11);
    Matrix con2_2 = new Matrix(con2_21);
    Matrix not = new Matrix(notupp);
    // getDim() method gets dimensions of con2_21 and con2_11
    
    // the first getElement() prints out con2_11, the second is for invalid position
    
    // for setElement, 
        int value1 = 100, value2 = 100;
        int setvalid_row1 = 3, setvalid_col1 = 4; // operates on con2_11
        int setvalid_row2 = 2, setvalid_col2 = 2;  //operates on con2_21
        int setinvalid_row1 = 7, setinvalid_col1 = 7;
        int setinvalid_row2 = 4, setinvalid_col2 = 0; // upper triangular part
    // fullMatrix() prints out con2_21 and con2_11 in 2D format
    
    /******** end parameters ****************/
    
		System.out.println("*** Test Class Matrix - 40' for this part ***" );
                System.out.println("*** The mark for each test case is indicated after the case number ***" );
                // test constructor1; invalid inputs
		Matrix a = new Matrix(invalid_row1,invalid_col1);
		System.out.println("No.1(1')->Test costructor1--invalid inputs: (" +invalid_row1 + "," + invalid_col1 + ")");
		System.out.println(a.toString());
		System.out.println("");
		
		// test constructor1; invalid inputs
		Matrix b = new Matrix(invalid_row2,invalid_col2);
		System.out.println("No.2(1')->Test costructor1--invalid inputs: (" +invalid_row2 + "," + invalid_col2 + ")");
		System.out.println(b.toString());
		System.out.println("");
				
		// test constructor1; valid inputs
		Matrix d = new Matrix(valid_row,valid_col);
		System.out.println("No.3(1')->Test costructor1--valid inputs: (" +valid_row + "," + valid_col + ")");
		System.out.println(d.toString());
		System.out.println("");
		
		//test constructor2;
		Matrix f = new Matrix(data);
		System.out.println("No.4(2')->Test costructor2-- " + data.length +"-by-"+ data[0].length +" array" );
		System.out.println(f.toString());
		System.out.println("");
		
		
		//test getElement(); Indices begin with 0
		
		try {
			System.out.println("No.5(1')->Test getElement(" + getvalid_row+ ","+ getvalid_col +"), Note that Indices begin with 0" );
			System.out.println(f.getElement(1, 3));			

			System.out.println("No.6(1')->Test getElement(" + getinvalid_row+ ","+ getinvalid_col +"), invalid indexes" );
			System.out.println(f.getElement(10, 2));	// invalid indexes
		}
		catch (IndexOutOfBoundsException e){
			System.out.println(e);
		}
		System.out.println("");
		
		System.out.println("No.7(2')->Test setElement() -- invalid operation (" + value+","+setinvalid_row+","+setinvalid_col+")" );
                System.out.println(f.setElement(value,setinvalid_row,setinvalid_col));
                System.out.println(f.toString());                
                System.out.println("No.8(2')->Test setElement() -- valid operation(" + value+","+setvalid_row+","+setvalid_col+")" );
                System.out.println(f.setElement(value,setvalid_row,setvalid_col));
                System.out.println(f.toString());		
		
                System.out.println("No.9(1')->Test copy()");
                System.out.println("copied matrix after modification");
                System.out.println(copied.toString());
                System.out.println("original matrix");
                System.out.println(origin.toString());
                
		System.out.println("No.10(3')->Test addTo() -- invalid operation");                
                Matrix m = new Matrix(add_to_data);
                try{
                    m.addTo(f);
                    System.out.println(m);
                }catch (ArithmeticException e){
			System.out.println(e);
			System.out.println("");
		}
                
                System.out.println("No.11(3')->Test addTo() -- valid operation");
                Matrix m1 = new Matrix(add_to_above);
                try{
                    m.addTo(m1);
                    System.out.println(m);
                }catch (ArithmeticException e){
			System.out.println(e);
			System.out.println("");
		}                
                                
                //test subMatrix()		
		try {
			System.out.println("No.12(3')->Test subMatrix(), valid inputs: (" +subvalid_row + "," + subvalid_col + ")");
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);
			System.out.println(y.toString());
			System.out.println("");

			System.out.println("No.13(3')->Test subMatrix(), invalid inputs: (" +subinvalid_row + "," + subinvalid_col + ")");
			System.out.println(f.subMatrix(subinvalid_row,subinvalid_col));
		}
		catch (ArithmeticException e){
			System.out.println(e);
			System.out.println("");
		}
		
		
		//test isUpperTr()	
		System.out.println("No.14(3')->Test isUpperTr(), return true");           	
        	Matrix v = new Matrix(Upper1);
		System.out.println(v.toString());
		System.out.println(v.isUpperTr());
                System.out.println("");

		System.out.println("No.15(3')->Test isUpperTr(), return false");		
        	Matrix n = new Matrix(notUpper1);
		System.out.println(n.toString()); 
		System.out.println(n.isUpperTr());
                System.out.println("");

		System.out.println("No.16(3')->Test isUpperTr(), return false (non-square matrix)");		
        	Matrix p = new Matrix(notUpper2);
		System.out.println(p.toString()); 
		System.out.println(p.isUpperTr());
                System.out.println("");

		
		System.out.println("No.17(3')->Test sum() -- invalid operation");
                try{
                    System.out.println(Matrix.sum(arr).toString());
                }
                catch (ArithmeticException e){
			System.out.println(e);
			System.out.println("");
		}
                
                System.out.println("No.18(3')->Test sum() -- valid operation");
                try{
                    System.out.println(Matrix.sum(arr2).toString());
                }
                catch (ArithmeticException e){
			System.out.println(e);
			System.out.println("");
		}
    }
    
}//end class

