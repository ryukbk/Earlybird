#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		glview = GLView::createWithRect("Early Bird", Rect(0, 0, 600, 400), 1);
#else
		glview = GLView::create("Early Bird");
#endif
	}

    director->setOpenGLView(glview);
	glview->setDesignResolutionSize(288,512, ResolutionPolicy::SHOW_ALL);

	// set the resource directory
	this->setResourceSearchResolution();
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = LoadingScene::create();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::setResourceSearchResolution()
{
    std::vector<std::string> paths;
	paths.push_back("fonts");
    paths.push_back("image");
    paths.push_back("sounds");
    FileUtils::getInstance()->setSearchResolutionsOrder(paths);
}


