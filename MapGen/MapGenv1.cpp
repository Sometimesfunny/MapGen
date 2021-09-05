//#include <fstream>
//#include <iostream>
//
//int main(void) {
//	int n = 0, m = 0, k = 0;
//	char s[256] = { 0 };
//	std::cout << "Please, enter map name: ";
//	std::cin >> s;
//	strcat_s(s, ".bin");
//	std::cout << "Please, enter map size (n, m) and objects number (k): ";
//	std::cin >> n >> m >> k;
//
//	std::ofstream file(s, std::ios::binary);
//	if (!file.is_open()) {
//		perror("Error");
//		return -1;
//	}
//	file.write((char*)&n, sizeof(n));
//	file.write((char*)&m, sizeof(m));
//	file.write((char*)&k, sizeof(k));
//	std::cout << "Now, enter " << k * 2 << "numbers (k coordinats):" << std::endl;
//	int l = 0;
//	for (int i = 0; i < k * 2; ++i) {
//		do
//		{
//			std::cin >> l;
//			if ((l >= m) || (l >= n))
//				std::cout << "Please, try again" << std::endl;
//		} while (l >= 10);
//		file.write((char*)&l, sizeof(l));
//	}
//	file.close();
//
//	return 0;
//}