#include<iostream>
#include<vector>
#include<string>
#include"canvas.h"
using namespace std;
vector<Shape*> v;
vector<string>dump_v;

int main() {
	int width, height;
	cin >> width >> height;

	Canvas canvas(width, height);
	canvas.Print();

	string menu;

	while (1) {
		cin >> menu;

		if (menu == "add") {
			string whatshape;
			cin >> whatshape;

			if (whatshape == "rect") {

				int x, y, rect_w, rect_h;
				char rect_b;
				cin >> x >> y >> rect_w >> rect_h >> rect_b;
				string v_r = "rect " + to_string(x) + " " + to_string(y) + " " + to_string(rect_w) + " " + to_string(rect_h) + " " + rect_b;
				dump_v.push_back(v_r);

				Shape* alloc_rec = new Rectangle(x, y, rect_w, rect_h, rect_b);
				v.push_back(alloc_rec);
			}
			else if (whatshape == "diamond") {
				int x, y, dia_d;
				char dia_b;
				cin >> x >> y >> dia_d >> dia_b;
				string v_d = "diamond " + to_string(x) + " " + to_string(y) + " " + to_string(dia_d) + " " + dia_b;
				dump_v.push_back(v_d);

				Shape* alloc_dia = new Diamond(x, y, dia_d, dia_b);
				v.push_back(alloc_dia);
			}
			else if (whatshape == "tri_up") {
				int x, y, up_h;
				char up_b;
				cin >> x >> y >> up_h >> up_b;
				string v_up = "tri_up " + to_string(x) + " " + to_string(y) + " " + to_string(up_h) + " " + up_b;
				dump_v.push_back(v_up);

				Shape* alloc_up = new UpTriangle(x, y, up_h, up_b);
				v.push_back(alloc_up);
			}
			else if (whatshape == "tri_down") {
				int x, y, down_h;
				char down_b;
				cin >> x >> y >> down_h >> down_b;
				string v_down = "tri_down " + to_string(x) + " " + to_string(y) + " " + to_string(down_h) + " " + down_b;
				dump_v.push_back(v_down);

				Shape* alloc_up = new DownTriangle(x, y, down_h, down_b);
				v.push_back(alloc_up);
			}
		}

		else if (menu == "delete") {
			int num;
			cin >> num;
			if (num >= v.size()) {
				continue;
			}
			v.erase(v.begin() + num);
		}

		else if (menu == "draw") {
			canvas.Clear();
			for (int i = 0; i < v.size(); i++) {
				v[i]->Draw(&canvas);
			}
			canvas.Print();
		}

		else if (menu == "dump") {
			for (int i = 0; i < v.size(); i++) {
				cout << i << " " << dump_v[i] << "\n";
			}
		}

		else if (menu == "resize") {
			int new_width, new_height;
			cin >> new_width >> new_height;
			canvas.Resize(new_width, new_height);
		}
		else if (menu == "quit") {
			break;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		delete v[i];
	}
	return 0;
}