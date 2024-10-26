def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i+1} (space-separated values): ").split()))
        matrix.append(row)
    return matrix

def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

print("Enter values for the first matrix:")
matrix1 = input_matrix(rows, cols)

print("Enter values for the second matrix:")
matrix2 = input_matrix(rows, cols)

result = add_matrices(matrix1, matrix2)
print("The result of matrix addition is:")
for row in result:
    print(row)
