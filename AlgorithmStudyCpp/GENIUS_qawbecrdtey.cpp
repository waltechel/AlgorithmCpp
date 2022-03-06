#pragma GCC optimize("Ofast")
#define NDEBUG
#include <iostream>
#include <vector>
using namespace std;
using ld = long double;
class matrix {
	vector<ld> mat;
	int n;
public:
	explicit matrix(int n) : mat(n * n), n(n) {}
	ld const &operator()(int r, int c) const { return mat[r * n + c]; }
	ld &operator()(int r, int c) { return mat[r * n + c]; }
	ld const &get(int r, int c) const { return mat[r * n + c]; }
	ld &get(int r, int c) { return mat[r * n + c]; }
	matrix &operator+=(matrix const &m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				get(i, j) += m(i, j);
			}
		}
		return *this;
	}
	matrix &operator-=(matrix const &m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				get(i, j) -= m(i, j);
			}
		}
		return *this;
	}
	matrix operator+(matrix const &m) const {
		matrix M(*this);
		return M += m;
	}
	matrix operator-(matrix const &m) const {
		matrix M(*this);
		return M -= m;
	}
	matrix operator*(matrix const &m) const {
		matrix res(n);
		if(n < 20) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						res(i, j) += get(i, k) * m(k, j);
					}
				}
			}
			return res;
		}
		if(n & 1) {
			matrix a(n + 1), b(n + 1);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					a(i, j) = get(i, j);
					b(i, j) = m(i, j);
				}
			}
			matrix mult = a * b;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					res(i, j) = mult(i, j);
				}
			}
			return res;
		}
		matrix m1(n >> 1), m2(n >> 1), m3(n >> 1), m4(n >> 1), m5(n >> 1), m6(n >> 1), m7(n >> 1);
		matrix a11(n >> 1), a12(n >> 1), a21(n >> 1), a22(n >> 1);
		matrix b11(n >> 1), b12(n >> 1), b21(n >> 1), b22(n >> 1);
		matrix c11(n >> 1), c12(n >> 1), c21(n >> 1), c22(n >> 1);
		for(int i = 0; i < (n >> 1); i++) {
			for(int j = 0; j < (n >> 1); j++) {
				a11(i, j) = get(i, j);
				a12(i, j) = get(i, j + (n >> 1));
				a21(i, j) = get(i + (n >> 1), j);
				a22(i, j) = get(i + (n >> 1), j + (n >> 1));
				b11(i, j) = m(i, j);
				b12(i, j) = m(i, j + (n >> 1));
				b21(i, j) = m(i + (n >> 1), j);
				b22(i, j) = m(i + (n >> 1), j + (n >> 1));
			}
		}
		m1 = (a11 + a22) * (b11 + b22);
		m2 = (a21 + a22) * b11;
		m3 = a11 * (b12 - b22);
		m4 = a22 * (b21 - b11);
		m5 = (a11 + a12) * b22;
		m6 = (a21 - a11) * (b11 + b12);
		m7 = (a12 - a22) * (b21 + b22);
		c11 = m1 + m4 - m5 + m7;
		c12 = m3 + m5;
		c21 = m2 + m4;
		c22 = m1 - m2 + m3 + m6;
		for(int i = 0; i < (n >> 1); i++) {
			for(int j = 0; j < (n >> 1); j++) {
				res(i, j) = c11(i, j);
				res(i, j + (n >> 1)) = c12(i, j);
				res(i + (n >> 1), j) = c21(i, j);
				res(i + (n >> 1), j + (n >> 1)) = c22(i, j);
			}
		}
		return res;
	}
	matrix &operator*=(matrix const &m) { return *this = *this * m; }
	static matrix identity(int n) {
		matrix mat(n);
		for(int i = 0; i < n; i++) mat(i, i) = 1;
		return mat;
	}
	friend matrix power(matrix const &m, int k) {
		if(!k) return identity(m.n);
		if(k == 1) return m;
		matrix r = power(m, k >> 1);
		r *= r;
		return r * power(m, k & 1);
	}
	friend vector<ld> mul(matrix const &m, vector<ld> const &v) {
		vector<ld> res(m.n);
		for(int i = 0; i < m.n; i++) {
			for(int j = 0; j < m.n; j++) {
				res[i] += m(i, j) * v[j];
			}
		}
		return res;
	}
	static matrix make_mat(int n, vector<int> const &len, matrix const &table) {
		matrix m(n << 2);
		for(int j = 0; j < n; j++) {
			for(int l = 0; l < n; l++) {
				m((l << 2) | len[l], j << 2) = table(j, l);
			}
			m(j << 2, (j << 2) | 1) = 1;
			m((j << 2) | 1, (j << 2) | 2) = 1;
			m((j << 2) | 2, (j << 2) | 3) = 1;
		}
		return m;
	}
	friend ostream &operator<<(ostream &os, matrix const &m) {
		for(int i = 0; i < m.n; i++) {
			for(int j = 0; j < m.n; j++) {
				os << m(i, j) << ' ';
			} os << '\n';
		}
		return os;
	}
};
inline ld ans(vector<ld> const &res, int x) { return res[(x << 2)] + res[(x << 2) | 1] + res[(x << 2) | 2] + res[(x << 2) | 3]; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(8); cout << fixed;

	int t; cin >> t; while(t--) {
		int n, k, m; cin >> n >> k >> m;
		vector<int> len(n);
		for(auto &now : len) { cin >> now; now--; }
		vector<ld> a(n << 2);
		a[len[0]] = 1;
		matrix table(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> table(i, j);
			}
		}
		auto mat = matrix::make_mat(n, len, table);
		auto matk = power(mat, k);
		auto res = mul(matk, a);
		while(m--) {
			int x; cin >> x;
			cout << ans(res, x) << ' ';
		} cout << '\n';
	}
/*
	int t; cin >> t; while(t--) {
		int n, k, m; cin >> n >> k >> m;
		auto len = new int[n];
		for(int i = 0; i < n; i++) { cin >> len[i]; len[i]--; }
		array<ld, 4>* a[2];
		a[0] = new array<ld, 4>[n]();
		a[1] = new array<ld, 4>[n]();
		a[0][0][len[0]] = 1;
		auto table = new ld*[n];
		for(int i = 0; i < n; i++) {
			table[i] = new ld[n];
			for(int j = 0; j < n; j++) cin >> table[i][j];
		}
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < n; j++) {
				ld const x = a[0][j][0];
				for(int l = 0; l < n; l++) {
					a[1][l][len[l]] += x * table[j][l];
				}
				a[1][j][0] += a[0][j][1];
				a[1][j][1] += a[0][j][2];
				a[1][j][2] += a[0][j][3];
			}
			swap(a[0], a[1]);
			fill(a[1], a[1] + n, array<ld, 4>{});
		}
		auto result = new ld[n]();
		for(int i = 0; i < n; i++) {
			for(ld now : a[0][i]) result[i] += now;
		}
		for(int i = 0; i < m; i++) {
			int x; cin >> x;
			cout << result[x] << ' ';
		} cout << '\n';
		delete[] result;
		delete[] len;
		delete[] a[0]; delete[] a[1];
		for(int i = 0; i < n; i++) delete[] table[i];
		delete[] table;

	}*/
}