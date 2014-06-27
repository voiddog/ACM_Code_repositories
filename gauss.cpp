void gauss(){   //n 行数， m列数， 答案存在增广矩阵m列
	int r, c, i, j;
	for (r = c = 0; r<n&&c<m; r++, c++){
		for (i = r; i<n; i++)
		if (save[i][c] != 0)break;
		if (i == n){ r--; continue; }
		if (i != r)for (j = c; j <= m; j++)swap(save[i][j], save[r][j]);
		for (i = r + 1; i<n; i++)
		if (save[i][c] != 0){
			double temp = save[i][c] / save[r][c];
			for (j = c; j <= m; j++)
				save[i][j] -= save[r][j] * temp;
		}
	}
	for (i = n - 1; i >= 0; i--){
		save[i][m] /= save[i][i];
		save[i][i] = 1;
		for (j = i - 1; j >= 0; j--)
			save[j][m] -= save[i][m] * save[j][i];
	}
}

int gauss(int n, int m){	//答案保存在x数组
	int i, j, k;
	int max_r;
	int col;
	double temp;
	int free_x_num;
	int free_index;
	int equ = n*m, var = n*m;
	col = 0;
	memset(free_x, true, sizeof(free_x));
	for (k = 0; k < equ && col < var; k++, col++){
		max_r = k;
		for (i = k + 1; i < equ; i++){
			if (sgn(fabs(save[i][col]) - fabs(save[max_r][col]))>0) max_r = i;
		}
		if (max_r != k){
			for (j = k; j < var + 1; j++) swap(save[k][j], save[max_r][j]);
		}
		if (sgn(save[k][col]) == 0){
			k--; continue;
		}
		for (i = k + 1; i < equ; i++){
			if (sgn(save[i][col]) != 0){
				double t = save[i][col] / save[k][col];
				for (j = col; j < var + 1; j++){
					save[i][j] = save[i][j] - save[k][j] * t;
				}
			}
		}
	}
	for (i = k; i<equ; i++)
	if (sgn(save[i][col]) != 0) { return 0; }
	if (k < var){
		for (i = k - 1; i >= 0; i--){
			free_x_num = 0;
			for (j = 0; j < var; j++){
				if (sgn(save[i][j]) != 0 && free_x[j]){
					free_x_num++, free_index = j;
				}
			}
			if (free_x_num>1)    continue;
			temp = save[i][var];
			for (j = 0; j < var; j++){
				if (sgn(save[i][j]) != 0 && j != free_index) temp -= save[i][j] * x[j];
			}
			x[free_index] = temp / save[i][free_index];
			free_x[free_index] = 0;
		}
		return var - k;
	}
	for (i = var - 1; i >= 0; i--){
		temp = save[i][var];
		for (j = i + 1; j < var; j++){
			if (sgn(save[i][j]) != 0) temp -= save[i][j] * x[j];
		}
		x[i] = temp / save[i][i];
	}
	return 0;
}
