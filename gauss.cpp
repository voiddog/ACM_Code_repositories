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
