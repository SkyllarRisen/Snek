/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/


#include "MainWindow.h"
#include "Board.h"
#include "Snake.h"
#include "Keyboard.h"
#include "Game.h"
#include <thread>
#include <chrono>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	snek(brd,{ 5,(brd.Height() - 1) / 2 }, Vectors::eX),
	obs(1, Obstacle(brd, snek.Pos(), snek.Vel(), snekFood.Pos())),
	snekFood(brd),
	moveCache(Vectors::eX)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

bool Game::GameEnd()
{
	return fGameEnd;
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
		fGameEnd = true;
	if (wnd.kbd.KeyIsPressed('W') && !(snek.Vel() == Vectors::eY))
		moveCache = -Vectors::eY;
	else if (wnd.kbd.KeyIsPressed('A') && !(snek.Vel() == Vectors::eX))
		moveCache = -Vectors::eX;
	else if (wnd.kbd.KeyIsPressed('S') && !(snek.Vel() == -Vectors::eY))
		moveCache = Vectors::eY;
	else if (wnd.kbd.KeyIsPressed('D') && !(snek.Vel() == -Vectors::eX))
		moveCache = Vectors::eX;

	if (snekMoveCounter >= snekMoveTime)
	{
		if (snek.MoveHead(moveCache))
			fGameEnd = true;
			
		if(snek.Eat(snekFood))
			++snekEatCounter;
		snekMoveCounter = 0;
	}
	else
		++snekMoveCounter;
	if (snekEatCounter >= 3)
	{
		if (level < brd.Height())
		{
			obs.push_back(Obstacle(brd, snek.Pos(), snek.Vel(), snekFood.Pos()));
			++level;
		}
		
		snekEatCounter = 0;
	}
		

}

void Game::ComposeFrame()
{
	brd.Draw();
	for (Obstacle& o : obs)
	{
		o.Draw();
	}
	snekFood.Draw();
	snek.Draw();
	if (fGameEnd)
	{
		using namespace std::this_thread;
		using namespace std::chrono_literals;
		using namespace std::chrono;
		sleep_for(2s);
	}
}
