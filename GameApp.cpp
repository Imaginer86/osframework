#include "GameApp.h"
#include "Board.h"

#include "SexyAppFramework/Common.h"
#include "SexyAppFramework/WidgetManager.h"
#include "SexyAppFramework/ImageFont.h"

using namespace Sexy;


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
GameApp::GameApp()
{
	// mProdName is used for internal purposes to indicate the game that we're working on
	mProdName = "FlowerSnake";

	// For internal uses, indicates the current product version
	mProductVersion = "1.0";

	// This is the text that appears in the title bar of the application window
	mTitle = StringToSexyStringFast(mProdName + " - " + mProductVersion);

	// Indicates the registry location where all registry keys will be read from
	// and written to. This is stored under the HKEY_CURRENT_USER tree on 
	// Windows systems.
	mRegKey = "PopCap\\SexyAppFramework\\FlowerSnake";

	// Set the application width/height in terms of pixels here.
	mWidth = 800;
	mHeight = 600;

	mBoard = NULL;
	mFont = NULL;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
GameApp::~GameApp()
{
	mWidgetManager->RemoveWidget(mBoard);
	delete mBoard;
	delete mFont;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void GameApp::Init()
{
	SexyAppBase::Init();

	// In later demos, you will see more done with this function.
	// For now, we have nothing else to initialize, so we are done.
	// Once complete, the LoadingThreadProc function will automatically
	// start and we will begin loading all our needed resources.
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void GameApp::LoadingThreadProc()
{
	mFont = new ImageFont(this,"fonts/Kiloton9.txt");

	// We need to check to see if the font was properly initialized.
	// If it wasn't, then an error occurred and we need to abort.
	if (!mFont->mFontData->mInitialized)
	{
		delete mFont;
		Popup("There was an error loading fonts/Kiloton9.txt");
		mLoadingFailed = true;
		return;
	}
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void GameApp::LoadingThreadCompleted()
{
	// Let the base app class also know that we have completed
	SexyAppBase::LoadingThreadCompleted();

	// When we're actually loading resources, we'll set the
	// mLoadingFailed variable to "true" if there were any problems
	// encountered along the way. If that is the case, just return
	// because we won't want the user to get to the main menu or any
	// other part of the game. We will want them to exit out.
	if (mLoadingFailed)
		return;

	// Now that we're done loading everything we need (which wasn't
	// anything in this particular demo), we need to get the main
	// game screen up and running: That is our "Board" class, and
	// it will handle all the drawing, updating, and input processing
	// for most of the game.
	mBoard = new Board(this);

	// This is a very important step: Because the Board class is a widget
	// (see Board.h/.cpp for more details) we need to tell it what
	// dimensions it has and where to place it. 
	// By default a widget is invisible because its
	// width/height are 0, 0. Since the Board class is our main
	// drawing area and game logic class, we want to make it the
	// same size as the application. For this particular demo, that means
	// 640x480. We will use mWidth and mHeight though, as those were
	// already set to the proper resolution in GameApp::Init().
	mBoard->Resize(0, 0, mWidth, mHeight);

	// Also an important step is to add the newly created Board widget to
	// the widget manager so that it will automatically have its update, draw,
	// and input processing methods called.
	mWidgetManager->AddWidget(mBoard);
}