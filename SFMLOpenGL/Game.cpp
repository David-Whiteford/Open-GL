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
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//opengl point
		glBegin(GL_POINTS);
		{
			glVertex3f(1.0, 2.0, -5.0);
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
				glVertex3f(0.0, 1.0, -5.0);
				glVertex3f(1.0, 0.0, -5.0);
			
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
			glVertex3f(-0.2, 0.2, -5.0);
			glVertex3f(-0.4, 0.2, -5.0);

			glVertex3f(-0.4, -0.2, -5.0);
			glVertex3f(-0.2, -0.2, -5.0);
			glVertex3f(0.6, -0.6, -5.0);
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
			glVertex3f(0.6, -0.6, -5.0);
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

