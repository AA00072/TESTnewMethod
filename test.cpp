

#include <iostream>
#include <cmath>

struct point {
	int x;
	int y;
};

int compareX(const void* a, const void* b) {
	point* p1 = (point*)a, * p2 = (point*)b;
	return (p1->x) - (p2->x);
}

int compareY(const void* a, const void* b) {
	point* p1 = (point*)a, * p2 = (point*)b;
	return (p1->y) - (p2->y);
}

float distance(point p1, point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float min(float x, float y) {
	return (x < y) ? x : y;
}

float bruteforce(point p[], int n) {
	if (n == 2)
		return (distance(p[0], p[1]));
	float min = INT16_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; i < n; i++) {
			if (distance(p[1], p[i]) < min)
				min = distance(p[i], p[j]);
		}
	}
	return min;
}

float stripClosest(point strip[], int size, float d) {
	if (size == 3 || size == 2) {
		return bruteforce(0, size);
	}
	int mid = size / 2;
	double dl = closestUtil(strip, mid);
	double dr = closestUtil(strip + mid, size - mid);
	double d = min(dl, dr);
	point p[size];
	int j = 0;

	for (int i = 0; i < size; i++) {
		if (abs(strip[mid].x - strip[mid].y)) {
			p[j] = p[i];
			j++;
		}
	}
}

float closestUtil(point p[], int n) {

}

int main()
{
	std::cout << "Hello World!\n";
}