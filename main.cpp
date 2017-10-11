#include <iostream>
#include <stdlib.h>
#include <time.h>

void fun_zap(int** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m_1[i][j] = rand() % 9 ;
		}
	}
}
void fun_zap_3(int** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m_1[i][j] = rand() % 9+1;
		}
	}
}

void fun_print(int** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << m_1[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void fun_zap_2(int** m_3, int** m_2 , int** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m_3[i][j] = m_1[i][j] + m_2[i][j];
		}
	}
}

int ** fun_dell(int** m_1, int n, int m, int id) {
	for (int i = id; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			m_1[i][j] = m_1[i + 1][j];
		}
	}
	free(m_1[n-1]);
	int** m_2 = (int**)realloc(m_1, (n - 1) * sizeof(int*));
	
	return m_2;
}

int** fun_dell_2(int** m_1, int* n, int m) {
	
	for (int i = 0; i < *n; ) {
		for (int j = 0; j < m; j++) {
			if (m_1[i][j] == 0) {
				m_1 = fun_dell(m_1, *n, m, i);
				(*n)--;
				
				break;
			}
			if (j == (m - 1)) {
				i++;
			}
		}
		
	}
	return m_1;
}

void fun_matrix(int** m_1, int** m_2, int** m_3, int n, int m, int n_t, int m_t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m_t; j++) {
			for (int k = 0; k < m; k++) {
				m_3[i][j] += m_1[i][k] * m_2[k][j];
			}
			
		}
	}
}



void fun_sdvig(int** m_1, int n, int m, int id_4, int id_5) {
	if (id_5 == 3 || id_5 == 4) {
		id_4 = id_4 % n;

	}
	else {
		id_4 = id_4 % m;
	}
	int temp = 0;
	if (id_5 == 1) {
		for (int q = 0; q < id_4; q++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m - 1; j++) {
					temp = m_1[i][j];
					m_1[i][j] = m_1[i][j + 1];
					m_1[i][j + 1] = temp;
				}
			}
		}
	}
	if (id_5 == 2) {
		for (int q = 0; q < id_4; q++) {
			for (int i = 0; i < n; i++) {
				for (int j = m-1; j >= 1; j--) {
					temp = m_1[i][j-1];
					m_1[i][j - 1] = m_1[i][j];
					m_1[i][j] = temp;
					
				}
			}
		}
	}
	if (id_5 == 3) {
		for (int q = 0; q < id_4; q++) {
			for (int i = 0; i < m; i++) {
				for (int j = n-1; j >=1; j--) {
					temp = m_1[j - 1][i];
					m_1[j - 1][i] = m_1[j][i];
					m_1[j][i] = temp;
				}
			}
		}
	}
	if (id_5 == 4) {
		for (int q = 0; q < id_4; q++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n-1; j++) {
					temp = m_1[j + 1][i];
					m_1[j+1][i] = m_1[j][i];
					m_1[j][i] = temp;
				}
			}
		}
	}


}


int main() {
	srand(time(NULL));
	int flag_menu = 0;
	int n = 0;
	int m = 0;

	do {
		std::cout << "\n" << "vvedite nomer zadani9" << "\n";
		std::cin >> flag_menu;

		if (flag_menu == 1) {
			std::cout << "\n" << "Zadanie nomer 1 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;

			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);
			std::cout << "\n" << "Sozdanie massiva 2 : " << "\n";
			int ** m_2 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_2[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_2, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_2, n, m);


			std::cout << "\n" << "Sozdanie massiva 3: " << "\n";
			int ** m_3 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_3[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap_2(m_3, m_2, m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_3, n, m);

			for (int i = 0; i < n; i++) {
				free(m_1[i]);
				free(m_2[i]);
				free(m_3[i]);
			}
			free(m_1);
			free(m_2);
			free(m_3);


		}


		if (flag_menu == 2) {
			std::cout << "\n" << "Zadanie nomer 2 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;
			int temp = 0;
			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);
			std::cout << "\n" << "Dell stroki s null elementami" << "\n";
			m_1=fun_dell_2(m_1, &n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, (n-temp), m);





			for (int i = 0; i < (n-temp); i++) {
				free(m_1[i]);
			}
			free(m_1);


		}


		if (flag_menu == 3) {
			int n_t = 0;
			int m_t = 0;
			std::cout << "\n" << "Zadanie nomer 3 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;

			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap_3(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);

			std::cout << "\n" << "Vvedite razmer massiva  2 N= ";
			std::cin >> n_t;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m_t;

			std::cout << "\n" << "Sozdanie massiva 2: " << "\n";
			int ** m_2 = (int**)calloc(n_t, sizeof(int*));
			for (int i = 0; i < n_t; i++) {
				m_2[i] = (int*)calloc(m_t, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap_3(m_2, n_t, m_t);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_2, n_t, m_t);

			std::cout << "\n" << "ymnohenie matric" << "\n";

			int ** m_3 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_3[i] = (int*)calloc(m_t, sizeof(int));
			}

			fun_matrix(m_1, m_2, m_3, n, m, n_t, m_t);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_3, n, m_t);





		}


		if (flag_menu == 4) {

			std::cout << "\n" << "Zadanie nomer 4 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;

			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);
			int id_4 = 0;
			int id_5 = 0;
			std::cout << "\n" << "Vvedite kol sdvigov" << "\n";
			std::cin >> id_4;
			std::cout << "\n" << "Vvedite napravlenie sdviga 1- vlevo, 2-vpravo,3-vniz,4-vverh" << "\n";
			std::cin >> id_5;

			std::cout << "\n" << "Sdvig : " << "\n";
			fun_sdvig(m_1, n, m, id_4, id_5);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);

		}
	
	
	
	
	
	} while (flag_menu != 0);





}