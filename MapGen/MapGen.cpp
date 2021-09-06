#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>
#include <vector>

class Coord
{
public:
    int x, y;
    Coord(int a, int b) :x(a), y(b) {};
    ~Coord() {};
    void operator+(Coord& a) {
        x = x + a.x;
        y = y + a.y;
        return;
    }
    void operator-(Coord& a) {
        x = x + a.x;
        y = y + a.y;
        return;
    }
    friend bool operator== (const Coord& a, const Coord& b) {
        return ((a.x == b.x) && (a.y == b.y));
    }
};

struct Object {
    int n;
    Coord coord;
};

void DrawSquare(float x, float y, float dx, float dy) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8f, 0.8f, 0.8f);//lower left
    glVertex2f(x - 1, y + dy - 1);
    glVertex2f(x - 1, y - 1);
    glVertex2f(x + dx - 1, y - 1);
    glColor3f(0.4f, 0.4f, 0.4f);//upper right
    glVertex2f(x + dx - 1, y + dy - 1);
    glEnd();
}
void DrawSquareBlue(float x, float y, float dx, float dy) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.1f, 0.9f);//lower left
    glVertex2f(x - 1, y + dy - 1);
    glVertex2f(x - 1, y - 1);
    glVertex2f(x + dx - 1, y - 1);
    glColor3f(0.2f, 0.3f, 0.7f);//upper right
    glVertex2f(x + dx - 1, y + dy - 1);
    glEnd();
}
void DrawLine(float x1, float y1, float x2, float y2, int c1 = 1, int c2 = 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple((c1+c2)%5 , 0x0f0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    switch ((c1 + c2) % 4) {
    case 0:
        glColor3f(0.2f, 1.0f, 0.4f);
        break;
    case 1:
        glColor3f(1.0f, 1.0f, 0.4f);
        break;
    case 2:
        glColor3f(0.5f, 0.5f, 0.0f);
        break;
    case 3:
        glColor3f(0.0f, 0.0f, 0.0f);
        break;
    }
    glVertex2f(x1 - 1, y1 - 1);
    glVertex2f(x2 - 1, y2 - 1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void DrawDigit(int n, int kx, int ky, int x, int y, float offset = 0.0f, float scale = 1.0f) {
    glPushMatrix();
    glScalef(1.0f / (float)kx, 1.0f / (float)ky, 1.0f);
    if (kx > ky)
        offset = offset * (float)kx / (float)ky;
    glTranslatef((float)x * 2 - kx + 1 + offset, (float)y * 2 - ky + 1, 0.0f);
    glLineWidth(2);
    glColor3f(0.89f, 0.67f, 0.2f);
    glScalef(scale, scale, 1.0f);
    switch (n)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f, -0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(-0.5f, 0.75f);
        break;
    case 1:
        glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(0.0f, -0.75f);
        glVertex2f(0.0f, 0.75f);
        glVertex2f(0.0f, 0.75f);
        glVertex2f(-0.5f, 0.25f);
        break;
    case 2:
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.5f, -0.75f);
        glVertex2f(0.5f, -0.75f);
        break;
    case 3:
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(-0.5f, -0.75f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        break;
    case 4:
        glBegin(GL_LINES);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(0.5f, -0.75f);
        break;
    case 5:
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(-0.5f, -0.75f);
        break;
    case 6:
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(-0.5f, -0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        break;
    case 7:
        glBegin(GL_LINE_STRIP);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(0.5f, -0.75f);
        break;
    case 8:
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f, -0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(-0.5f, 0.75f);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        break;
    case 9:
        glBegin(GL_LINE_STRIP);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.5f, 0.75f);
        glVertex2f(0.5f, 0.75f);
        glVertex2f(0.5f, -0.75f);
        glVertex2f(-0.5f, -0.75f);
        break;
    default:
        break;
    }
    glEnd();
    glPopMatrix();
}

int main(void) {
	int n = 0, m = 0;

	std::cout << "Please, enter map size (n, m): ";
	std::cin >> n >> m;

    std::cout << "Click LMB to place/link object.\nPress M to change mode (Placing/Linking)" \
        << std::endl;
	
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(600, 600, "Map Generator", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

    HWND hwnd = FindWindow(NULL, TEXT("Map Generator"));
    int xfield = n, yfield = m; // Fields counter
    int width = 0;
    int height = 0;
    float w = 1, h = 1; // Screen coeffs
    int offsetx = 0, offsety = 0;
    float dx = 2.0f / xfield, dy = 2.0f / yfield; // Field size
    POINT p; // Screen point
    std::vector<Coord> arr; // Objects coords vector
    std::vector<std::vector<int>> links; // linkings
    std::vector<int> buf; // Linking buffer
    int cnt;
    bool f = 1, fbuf = 1; // Flags
    enum Modes { SQUARES, LINES }; //Drawing modes
#pragma warning(push)
#pragma warning(disable: 26812)
    Modes mode = SQUARES; // Default mode
#pragma warning(pop)
    bool scaleflag = true;

	/* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glfwGetWindowSize(window, &width, &height);

        offsetx = 0, offsety = 0;
        w = 1, h = 1;
        // Scaling image
        if (xfield < yfield) {
            if (width >= height) {
                w = (float)height / (float)width;
                offsetx = (width - height) / 2;
                scaleflag = true;
            }
            else if ((xfield < yfield) && (width < height) && \
                (width > (height * (float)xfield / (float)yfield))) {
                w = (float)height / (float)width;
                offsetx = (width - height) / 2;
                scaleflag = true;
            }
            else {
                width = (float)width * (float)yfield / (float)xfield;
                h = (float)width / (float)height;
                offsety = (height - width) / 2;
                width = width * (float)xfield / (float)yfield;
                scaleflag = false;
            }
        }
        else {
            if (height >= width) {
                h = (float)width / (float)height;
                offsety = (height - width) / 2;
                scaleflag = true;
            }
            else if ((yfield < xfield) && (width > height) && \
                (height > (width * (float)yfield / (float)xfield))) {
                h = (float)width / (float)height;
                offsety = (height - width) / 2;
                scaleflag = true;
            }
            else {
                height = (float)height * (float)xfield / (float)yfield;
                w = (float)height / (float)width;
                offsetx = (width - height) / 2;
                height = height * (float)yfield / (float)xfield;
                scaleflag = false;
            }
        }
        
        glViewport(offsetx, offsety, (int)width * w, (int)height * h);

        glLoadIdentity();
        if (scaleflag)
            if (yfield > xfield)
                glScalef((float)xfield / (float)yfield, 1.0f, 1.0f);
            else
                glScalef(1.0f, (float)yfield / (float)xfield, 1.0f);

        //Check LMB press
        if (GetKeyState(VK_LBUTTON) & (1 << (sizeof(short) * 8 - 1))) {
            GetCursorPos(&p);
            ScreenToClient(hwnd, &p);
            int x = 0, y = 0;
            if (xfield < yfield) {
                w = height * (float)xfield / (float)yfield;
                offsetx = (height - w) / 2 + offsetx;
            }
            else if (xfield > yfield) {
                h = width * (float)yfield / (float)xfield;
                offsety = (width - h) / 2 + offsety;
            }
            if ((p.x > offsetx) && (p.x < (width - offsetx)) && \
                (p.y > offsety) && (p.y < (height - offsety))) {
                x = (float)(p.x - offsetx) / (float)(width - 2 * offsetx) * xfield;
                y = yfield - (float)(p.y - offsety) / (float)(height - 2 * offsety)* yfield;
                // Put square
                if (mode == SQUARES) {
                    for (UINT i = 0; i < arr.size(); ++i) {
                        if (arr[i] == Coord(x, y)) {
                            f = 0;
                            break;
                        }
                    }
                    if (f) {
                        arr.push_back(Coord(x, y));
                        links.push_back(std::vector<int>());
                    }
                    f = 1;
                }
                // Put line
                else {
                    for (UINT i = 0; i < arr.size(); ++i) {
                        if (arr[i] == Coord(x, y)) {
                            f = 0;
                            cnt = i;
                            break;
                        }
                    }
                    if (!f)
                        buf.push_back(cnt);
                    if (buf.size() == 2)
                        if (buf[0] == buf[1]) {
                            std::cout << "Unable to link object" << std::endl;
                            buf.clear();
                        }
                    if (buf.size() == 2) {
                        for (UINT i = 0; i < links[buf[0]].size(); ++i) {
                            if (links[buf[0]][i] == buf[1]) {
                                fbuf = 0;
                                std::cout << "Already linked" << std::endl;
                                break;
                            }
                        }
                        if (fbuf) {
                            links[buf[0]].push_back(buf[1]);
                            links[buf[1]].push_back(buf[0]);
                            std::cout << "Linked [" << buf[0] << "] and [" << \
                                buf[1] << "]" << std::endl;
                        }
                        fbuf = 1;
                        buf.clear();
                    }
                    f = 1;
                }
            }
            Sleep(100);
        }
        // Change mode if 'M' pressed
        if (GetKeyState('M') & (1 << (sizeof(short) * 8 - 1))) {
            if (mode == SQUARES) {
                mode = LINES;
                std::cout << "LINES" << std::endl;
            }
            else {
                mode = SQUARES;
                std::cout << "SQUARES" << std::endl;
            }
            Sleep(100);
        }

        UINT k;
        // Draw Squares and digits
        for (int i = 0; i < yfield; ++i)
            for (int j = 0; j < xfield; ++j) {
                k = 0;
                while ((k < arr.size()) && !(Coord(j, i) == arr[k]))
                    k = k + 1;
                if (k < arr.size()) {
                    DrawSquareBlue(j * dx, i * dy, dx, dy);
                    if (k < 10)
                        DrawDigit(k, xfield, yfield, j, i);
                    else {
                        DrawDigit(k / 10, xfield, yfield, j, i, -dx, 0.6f);
                        DrawDigit(k % 10, xfield, yfield, j, i, +dx, 0.6f);
                    }
                    
                }
                else {
                    DrawSquare(j * dx, i * dy, dx, dy);
                }
            }
        // Draw lines
        for (UINT i = 0; i < arr.size(); ++i) {
            for (UINT j = 0; j < links[i].size(); ++j) {
                if (links[i][j] > i) {
                    DrawLine((float)arr[i].x * dx + dx / 2.0f, \
                        (float)arr[i].y * dy + dy / 2.0f, \
                        (float)arr[links[i][j]].x * dx + dx / 2.0f, \
                        (float)arr[links[i][j]].y * dy + dy / 2.0f, i, j);
                }
            }
        }
        Sleep(16);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

	return 0;
}