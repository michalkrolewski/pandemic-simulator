#pragma once
struct Field {
	int width = 50;
	int height = 50;
	int size() {
		return width * height;
	}
};