/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// EXTERNAL INCLUDES
#include <string>
#include <dali/dali.h>
#include <dali/integration-api/adaptor-framework/adaptor.h>
#include <dali-toolkit/dali-toolkit.h>
#include <dali/devel-api/adaptor-framework/window-devel.h>

// INTERNAL INCLUDES
#include "visual-test.h"

using namespace Dali;
using namespace Dali::Toolkit;

namespace
{

const std::string IMAGE_FILE_1 = TEST_IMAGE_DIR "thank-you/expected-result-1.png";
}  // namespace

/**
 * @brief This is to test the functionality which allows the uploading of textures to the GPU
 * without rendering while the application is paused, and thus, have them available immediately
 * for rendering on resume.
 */
class ThankYouTest: public VisualTest
{
 public:

  ThankYouTest( Application& application )
    : mApplication( application )
  {
  }

  void OnInit( Application& application )
  {
    Dali::Window window = mApplication.GetWindow();
    window.SetBackgroundColor(Color::WHITE);

    mTextLabel = TextLabel::New( "Thank you" );
    mTextLabel.SetProperty( Actor::Property::ANCHOR_POINT, AnchorPoint::TOP_LEFT );
    window.Add( mTextLabel );
    
    CaptureWindow( mApplication.GetWindow() );
  }

private:

  void PostRender()
  {
    DALI_ASSERT_ALWAYS( CheckImage( IMAGE_FILE_1, 0.95f ) ); // verify the similarity
    // DALI_ASSERT_ALWAYS( CheckImage( IMAGE_FILE_1 ) );
    mApplication.Quit();
  }

private:

  Application& mApplication;
  TextLabel    mTextLabel;
};

DALI_VISUAL_TEST( ThankYouTest, OnInit )

