/// David Whiteford
/// 5 hrs
/// Open-GL
/// Investigate the use of open gl 
/// part1 and 2 are in game.cpp with part 2 commeted out
/// part 1 includes the glScalef(1.0f, 1.0f, 1.0f) , glTranslatef(1.0f, 0.0f, 0.0f) , glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f) m,glLoadIdentity()

#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x 
		/ window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);


}

void Game::update()
{
			rotationAngle += 0.005f;
	
			if (rotationAngle > 360.0f)
			{
				rotationAngle -= 360.0f;
			}
		
		


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
			}	
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				glRotatef(-rotationAngle, 0.0f, 0.0f, 1.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				glTranslatef(0.01f, 0.01f, 0.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				glTranslatef(-0.01f, -0.01f, 0.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				glScalef(0.9f, 0.9f, 1.0f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{

				glLoadIdentity();
			}
	
	
	
	cout << "Update up" << endl;

}

void Game::draw()
{

	
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//opengl triangle
		glBegin(GL_TRIANGLES);
		{
			glVertex3f(0.0, 0.2, -5.0);
			glVertex3f(-0.2, -0.2, -5.0);
			glVertex3f(0.2, -0.2, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//opengl point
		glBegin(GL_POINTS);
		{
			glVertex3f(1.0, 2.0, -5.0);
			glVertex3f(-1.0, 2.0, -5.0);
			glVertex3f(-1.0, -2.0, -5.0);
			glVertex3f(1.0, -2.0, -5.0);
		}
		glEnd();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		//opengl lines
		glBegin(GL_LINES);
		{
			glVertex3f(1.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
		}
		glEnd();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//opengl line Strip
		glBegin(GL_LINE_STRIP);
		{
			glVertex3f(-0.4, 0.0, -5.0);
			glVertex3f(-0.3, 0.2, -5.0);
			glVertex3f(-0.2, 0.0, -5.0);
			glVertex3f(-0.1, 0.2, -5.0);
			glVertex3f(0.0, 0.0, -5.0);
			glVertex3f(0.1, 0.2, -5.0);
			glVertex3f(0.2, 0.0, -5.0);
			glVertex3f(0.3, 0.2, -5.0);
			glVertex3f(0.4, 0.0, -5.0);
		}
		glEnd();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		//opengl line Strip
		glBegin(GL_LINE_LOOP);
		{
				glVertex3f(-1.0, 0.0, -5.0);
				glVertex3f(0.0, -1.0, -5.0);
				glVertex3f(1.0, 0.0, -5.0);
				glVertex3f(0.0, 1.0, -5.0);
			
			glEnd();
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		//opengl line Strip
		glBegin(GL_TRIANGLE_STRIP);
		{
			glVertex3f(0.0, 0.2, -5.0);
			glVertex3f(-0.2, -0.2, -5.0);
			glVertex3f(0.2, -0.2, -5.0);

			glVertex3f(-0.1, 0.2, -5.0);
			glVertex3f(0.2, 0.2, -5.0);
			glVertex3f(0.0, -0.5, -5.0);


			glEnd();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		//opengl triangle
		glBegin(GL_QUADS);
		{
			glVertex3f(0.6, 0.6, -5.0);
			glVertex3f(-0.4, 0.4, -5.0);
			glVertex3f(-0.6, 0.4, -5.0);
			glVertex3f(-0.4, 0.8, -5.0);

			glVertex3f(-0.4, -0.2, -5.0);
			glVertex3f(-0.2, -0.2, -5.0);
			glVertex3f(0.6, -0.6, -5.0);
			glVertex3f(-0.7, 0.6, -5.0);
		}
		glEnd();
	}



	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		//opengl line Strip
		glBegin(GL_QUAD_STRIP);
		{
			glVertex3f(0.6, 0.6, -5.0);
			glVertex3f(-0.2, 0.2, -5.0);
			glVertex3f(-0.4, 0.2, -5.0);

			glVertex3f(-0.4, -0.2, -5.0);
			glVertex3f(-0.2, -0.2, -5.0);
			glVertex3f(0.2, -0.2, -5.0);
		}
			glEnd();
		
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
	//opengl line Strip
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0, 0.3, -5.0);
		glVertex3f(0.2, 0.3, -5.0);
		glVertex3f(0.3, 0.2, -5.0);

		glVertex3f(0.35, 0.05, -5.0);
		glVertex3f(0.3, -0.1, -5.0);
		glVertex3f(0.2, -0.2, -5.0);



		glVertex3f(0.0, -0.25, -5.0);
		glVertex3f(-0.2, -0.2, -5.0);
		glVertex3f(-0.3, -0.1, -5.0);

		glEnd();
	}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
	//opengl lines
	glBegin(GL_POLYGON);
	{
		glVertex3f(-1.0f, 1.0f, -5.0);	// Top Left
		glVertex3f(1.0f, 1.0f, -5.0);	// Top Right
		glVertex3f(1.0f, -1.0f, -5.0);	// Bottom Right
		glVertex3f(-1.0f, -1.0f, -5.0);	// Bottom Left
	}
	glEnd();
	}



	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}








//// //  Part 2
//// // ********************
//bool flip = false;
//int current = 1;
//// // ********************
//
//  //Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
//  
//
//Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
//{
//	// // Part 2
//	// // ********************
//	 index = glGenLists(primatives);
//	// // ********************
//}
//
//Game::~Game() {}
//
//void Game::run()
//{
//
//	initialize();
//
//	Event event;
//
//	while (isRunning) {
//
//		cout << "Game running..." << endl;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				isRunning = false;
//			}
//		}
//		update();
//		draw();
//	}
//
//}
//
//void Game::initialize()
//{
//	isRunning = true;
//
//	// // Part 2
//	// // ********************
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
//	glMatrixMode(GL_MODELVIEW);
//
//
//	glNewList(index, GL_COMPILE);
//	glBegin(GL_TRIANGLES);
//	{
//	
//		glColor3f(0.0f, 0.0f, 1.0f);
//		glVertex3f(0.0, 0.2, -5.0);
//		glVertex3f(-0.2, -0.2, -5.0);
//		glVertex3f(0.2, -0.2, -5.0);
//	}
//	glEnd();
//	glEndList();
//
//	glNewList(index + 1, GL_COMPILE);
//	glBegin(GL_TRIANGLES);
//	{
//		glColor3f(0.0f, 0.1, 0.0f);
//		glVertex3f(0.2, 0.0, -2.0);
//		glVertex3f(-0.2, -0.2, -2.0);
//		glVertex3f(0.2, -0.2, -2.0);
//		
//	}
//	glEnd();
//	glEndList();
//
//	// // Part 2
//	// // ********************
//}
//
//void Game::update()
//{
//
//	// // Part 2
//	// // ********************
//	elapsed = clock.getElapsedTime();
//
//	if (elapsed.asSeconds() >= 1.0f)
//	{
//		clock.restart();
//
//		if (!flip)
//		{
//			flip = true;
//			current++;
//			if (current > primatives)
//			{
//				current = 1;
//			}
//		}
//		else
//			flip = false;
//	}
//
//	if (flip)
//	{
//		rotationAngle += 0.005f;
//
//		if (rotationAngle > 360.0f)
//		{
//			rotationAngle -= 360.0f;
//		}
//	
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
//	{
//		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
//	}	
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//	{
//		glRotatef(-rotationAngle, 0.0f, 0.0f, 1.0f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		glTranslatef(0.01f, 0.01f, 0.0f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		glTranslatef(-0.01f, -0.01f, 0.0f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
//	{
//		glScalef(1.0f, 1.0f, 1.0f);
//	}
//
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//	{
//		glLoadIdentity();
//	}
//	cout << "Update up" << endl;
//}
//
//void Game::draw()
//{
//
//	// // Part 2
//	// // ********************
//	cout << "Draw up" << endl;
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//
//	cout << "Drawing Primative " << current << endl;
//	glCallList(current);
//	// // Part 2
//	// // ********************
//
//	window.display();
//
//}
//
//void Game::unload()
//{
//	cout << "Cleaning up" << endl;
//}
//
