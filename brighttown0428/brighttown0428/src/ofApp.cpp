#include "ofApp.h"
#include "windows.h"
#include "effects.h"
//--------------------------------------------------------------
void ofApp::setup() {
	//sphere.setRadius(5000);
			// <-------- setup the GL context

	//ofHideCursor();


	//sound.setPositionMS(180000);

	ofHideCursor();

	sound.loadSound("BrightTownRH2.mp3");
	lines.clear();
	movinglines.clear();
	brighttowns.clear();
	lineemitparticles.clear();
	sxplayelement.clear();
	sxplayparticles.clear();
	brightpoints.clear();
	movingTriangles.clear();
	movingTriangles2.clear();
	movingTriangles3.clear();
	movingTriangles4.clear();
	movinglines2.clear();
	burstTriangles.clear();
	boxes.clear();
	controlboxes.clear();
	cylinders.clear();
	controlcylinders.clear();
	rollTriangles.clear();
	rollTriangles2.clear();
	movingpoints.clear();
	linepoints.clear();
	spheres.clear();
	ofBackground(0, 0, 0);
	ofSetFrameRate(30);
	ofEnableSmoothing();
	ofSetVerticalSync(true);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	image[0].loadImage("thesxplay.jpg");
	image[1].loadImage("t.jpg");
	image[2].loadImage("brighttown.jpg");

	for (int k = 0; k < 3; k++)
	{
		pixels[k] = image[k].getPixels().getData();
		//画像の幅と高さを所得
		w[k] = image[k].getWidth();
		h[k] = image[k].getHeight();
		picpoint[k][0].clear();
		picpoint[k][1].clear();

		for (int i = 0; i < w[k]; i += 4)
		{
			for (int j = 0; j < h[k]; j += 4)
			{
				int valueR = pixels[k][j * 3 * w[k] + i * 3];

				if (valueR < 10)
				{
					double x = i - w[k] / 2;
					double y = j - h[k] / 2;
					picpoint[k][0].push_back(sqrt(x*x + y*y));
					if (x < 0)
					{
						if (y < 0)
						{
							picpoint[k][1].push_back(atan(y / x) + M_PI);
						}
						else
						{
							picpoint[k][1].push_back(atan(y / x) + M_PI);
						}
					}
					else
					{
						if (y < 0)
						{
							picpoint[k][1].push_back(atan(y / x));
						}
						else
						{
							picpoint[k][1].push_back(atan(y / x));
						}
					}
				}
			}
		}

	}
	sxplaypoint[0] = { 20,520 };
	sxplaypoint[1] = { 370,265 };
	sxplaypoint[2] = { 130,235 };
	sxplaypoint[3] = { 255,30 };
	sxplaypoint[4] = { 300,30 };
	sxplaypoint[5] = { 355,30 };
	sxplaypoint[6] = { 300,135 };
	sxplaypoint[7] = { 355,80 };
	sxplaypoint[8] = { 355,135 };
	sxplaypoint[9] = { 405,80 };
	sxplaypoint[10] = { 405,135 };
	sxplaypoint[11] = { 405,30 };
	sxplaypoint[12] = { 420,80 };
	sxplaypoint[13] = { 470,30 };
	sxplaypoint[14] = { 520,80 };
	sxplaypoint[15] = { 455,105 };
	sxplaypoint[16] = { 295,415 };
	sxplaypoint[17] = { 440,415 };
	sxplaypoint[18] = { 460,175 };
	sxplaypoint[19] = { 460,340 };
	sxplaypoint[20] = { 460,415 };
	sxplaypoint[21] = { 600,240 };
	sxplaypoint[22] = { 610,175 };
	sxplaypoint[23] = { 610,415 };
	sxplaypoint[24] = { 695,415 };
	sxplaypoint[25] = { 825,175 };
	sxplaypoint[26] = { 825,415 };
	sxplaypoint[27] = { 850,175 };
	sxplaypoint[28] = { 850,415 };
	sxplaypoint[29] = { 915,290 };
	sxplaypoint[30] = { 980,175 };
	double kakudai = 2;
	for (int i = 0; i < 31; i++)
	{
		sxplaypoint[i].x = (double)sxplaypoint[i].x*kakudai + (ofGetWidth() / 2 - w[0] / 2 * kakudai);
		sxplaypoint[i].y = (double)sxplaypoint[i].y*kakudai + (ofGetHeight() / 2 - h[0] / 2 * kakudai);
	}
	for (int i = 0; i < 31; i++)
	{
		sxplayL[i] = sqrt((sxplaypoint[i].x - ofGetWidth() / 2)*(sxplaypoint[i].x - ofGetWidth() / 2) + (sxplaypoint[i].y - ofGetHeight() / 2)*(sxplaypoint[i].y - ofGetHeight() / 2));
		sxplayDig[i] = atan((sxplaypoint[i].y - ofGetHeight() / 2) / (sxplaypoint[i].x - ofGetWidth() / 2));
		if ((sxplaypoint[i].x - ofGetWidth() / 2) < 0)
		{
			sxplayDig[i] += M_PI;
		}

	}
	sxpointline[0] = { 0,1 };
	sxpointline[1] = { 1,2 };
	sxpointline[2] = { 2,7 };
	sxpointline[3] = { 3,5 };
	sxpointline[4] = { 4,6 };
	sxpointline[5] = { 3,17 };
	sxpointline[6] = { 15,16 };
	sxpointline[7] = { 5,8 };
	sxpointline[8] = { 7,9 };
	sxpointline[9] = { 11,10 };
	sxpointline[10] = { 13,14 };
	sxpointline[11] = { 12,13 };
	sxpointline[12] = { 12,14 };
	sxpointline[13] = { 12,21 };
	sxpointline[14] = { 19,21 };
	sxpointline[15] = { 18,20 };
	sxpointline[16] = { 22,23 };
	sxpointline[17] = { 23,24 };
	sxpointline[18] = { 24,25 };
	sxpointline[19] = { 25,26 };
	sxpointline[20] = { 27,29 };
	sxpointline[21] = { 28,30 };



	text.loadFont("arial.ttf", 72);


}

//--------------------------------------------------------------
void ofApp::update(){
	
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (loadmusic)
	{
		time = ofGetElapsedTimeMillis();
		musictime = sound.getPositionMS();
		fft = ofSoundGetSpectrum(512);
		soundvol = 0;
		for (int i = 0; i < 350; i++)
		{
			soundvol += fft[i];
		}
		soundvolave = (soundvol + 100 * soundvolave) / 101;
		ofSetColor(0, 0, 0);
		int mode;
		if (musictime < 8500)//音に応じてbrighttown明滅
		{
			mode = 0;
		}
		else if (musictime < 15000)//brighttownカラーになる
		{
			mode = 1;
		}
		else if (musictime < 17200)//ボール飛び散る
		{
			mode = 2;
		}
		else if (musictime < 23050)//棒が出る
		{
			mode = 3;
		}
		else if (musictime < 30400)//棒が出て消える、最後に大きい波紋最後にボールを放つ
		{
			mode = 4;
		}
		else if (musictime < 37000)//棒が出て消える、最後にボールを放つ
		{
			mode = 5;
		}
		else if (musictime < 40700)//棒が出て消える、最後にボールを放つ
		{
			mode = 6;
		}
		else if (musictime < 44500)
		{
			mode = 7;
		}
		else if (musictime < 45000)
		{
			mode = 8;
		}
		else if (musictime < 45500)
		{
			mode = 9;
		}
		else if (musictime < 46000)
		{
			mode = 10;
		}
		else if (musictime < 52000)
		{
			mode = 11;
		}
		else if (musictime < 59000)
		{
			mode = 12;
		}
		else if (musictime < 65000)
		{
			mode = 13;
		}
		else if (musictime < 71500)
		{
			mode = 14;
		}
		else if (musictime < 79000)
		{
			mode = 15;

		}
		else if (musictime < 87000)
		{
			mode = 16;
		}
		else if (musictime < 87250)
		{
			mode = 17;
		}
		else if (musictime < 92500)
		{
			mode = 18;
		}
		else if (musictime < 100000)
		{
			mode = 19;
		}
		else if (musictime < 107000)
		{
			mode = 20;
		}
		else if (musictime < 111000)
		{
			mode = 21;
		}
		else if (musictime < 113000)
		{
			mode = 22;
		}
		else if (musictime < 115000)
		{

			mode = 23;
		}
		else if (musictime < 116500)
		{
			sxplaytime = 115000;
			mode = 24;
		}
		else if (musictime < 122000)
		{
			liningtime1 = 115400;
			mode = 25;
		}
		else if (musictime < 129000)
		{

			mode = 26;
		}
		else if (musictime < 136000)
		{

			mode = 27;
		}
		else if (musictime < 141000)
		{

			mode = 28;
		}
		else if (musictime <170750)////153500
		{
			emittingtime1 = 141000;
			mode = 29;
		}
		else if (musictime < 183850)
		{
			emittingtime3 = 170750;
			mode = 30;
		}
		else if (musictime < 183950)
		{
			mode = 31;
		}
		else if (musictime < 191000)
		{
			mode = 32;
		}
		else if (musictime < 200000)
		{
			commingparticle2time = 191000;
			mode = 33;
		}
		else if (musictime < 207000)
		{
			mode = 34;
		}
		else if (musictime < 213000)
		{
			mode = 35;
		}
		else if (musictime < 218500)
		{
			rollingtime = 213000;
			mode = 36;
		}
		else if (musictime < 225000)
		{
			bigtriangletime = 218500;
			mode = 37;
		}
		else if (musictime < 241500)
		{
			mode = 38;
		}
		else if ((musictime < 250000))
		{
			commingparticle2time = 241500;
			brighttowntime = 250000;
			mode = 39;
		}
		else
		{

			mode = 40;
		}


		/*ofSetColor(255, 255, 255);
		text.drawString(ofToString(mode), ofGetWidth() / 6 * 5, ofGetHeight() / 5);*/
		//1番
		brighttowneffect(mode);//0,1,2
		lineeffectv2(mode);//3,4,5,6,7
		lineeffectv3(mode);//7,8
		sxplayburst(mode);//9,10,11
		//balllines(mode);
		circles(mode);//11,12,13,14,15,16,17
		//linesonpic(mode);
		brightingpoint(mode);//9,10,11,12,13,14,15,16,17
		//2番
		triangleeffect(mode);//18,19,20,21,22
		triangleeffectv2(mode);//22,23
		triangleburst(mode);//23,24,25,26,27
		triangleemitter(mode);//26,27,28,29,30
		//cメロ
		infiniteburst(mode);//31
		throughsxplay(mode);//32
		commingparticle(mode);
		commingparticle2(mode);
		rollingbox(mode);
		downcylinder(mode);
		rollingtriangle(mode);
		//bigtriangle(mode);
		pointeffect(mode);
		brighttowneffect2(mode);
	
	}
}


void ofApp::plot(float *buffer, float scale) {
	ofNoFill();
	int n = 300;

	ofPushMatrix();
	ofTranslate(0, scale * 3);
	ofScale(1, -scale);
	ofBeginShape();
	for (int i = 0; i < n; i++) {
		ofVertex((double)i / n * 1024, buffer[i] * 10);
	}
	ofEndShape();
	ofPopMatrix();
}

void ofApp::circles(int mode1) 
{
	
	double kakudai = 2;
	
	int mode = mode1-11;
	if (mode >= 0&&mode<7)
	{
		//球体表示
		/*sphere.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
		sphere.rotate(1, ofNoise(0,soundvol), 0.0, 0.0);
		sphere.rotate(1, 0, 1.0, 0.0);
		ofSetColor(0, 0, 255, 50);

		sphere.drawWireframe();*/

		
		//画像を8ピクセル間隔でスキャン
		for (int i = 0; i < w[0]; i += 9) 
		{
			for (int j = 0; j < h[0]; j += 7)
			{

				//ピクセルのRGBの値を取得
				int valueR = pixels[0][j * 3 * w[0] + i * 3];
				int valueG = pixels[0][j * 3 * w[0] + i * 3 + 1];
				int valueB = pixels[0][j * 3 * w[0] + i * 3 + 2];
				if (valueB < 70)
				{
					//取得したRGB値をもとに、円を描画
					//取得したピクセルの明るさを、円の半径に対応させている

					double R = fft[(int)ofRandom(30, 150)] * 1.8;
					/*if (R > 10)
					{
						R = 10;
					}*/

					ofFill();
					if (mode == 17)
					{
						ofSetColor(fft[(int)ofRandom(0, 150)] * 1500, fft[(int)ofRandom(0, 150)] * 1500, fft[(int)ofRandom(0, 150)] * 1500, soundvol* ofRandom(170, 200)*(87250 - musictime));
					}
					else
					{
						ofSetColor(fft[(int)ofRandom(0, 150)] * 2500, fft[(int)ofRandom(0, 150)] * 2500, fft[(int)ofRandom(0, 150)] * 2500, soundvol * 40 * ofRandom(200, 250));
					}
					ofCircle((double)i*kakudai + (ofGetWidth() / 2 - w[0] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[0] / 2 * kakudai), R* ofGetHeight() / 2);


				}
			}
		}
	}
	
}



void ofApp::lineeffectv2(int mode)
{
	int time = ofGetElapsedTimeMillis();
	int mode1 = mode ;
	
	if ((mode1  >= 3&& mode1 <8 ))
	{
		if (mode1 != 7)
		{
			if (ofGetElapsedTimeMillis() % 430 < 80 && lineeffectv2timing)
			{
				for (int j = 0; j<1; j++)
				{
					for (int i = 0; i < 100; i++)
					{
						if (mode == 6)
						{
							if (fft[i] * 1000 > 60)
							{

								Line myline;

								if (i % 3 == 0)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 25, 0, ofRandom(1000, 255), ofRandom(100, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								else if (i % 3 == 1)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 25, -fft[i] * 25, ofRandom(100, 255), ofRandom(0, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								else
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, -fft[i] * 25, ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								if (lineeffectv2count % 2 == 0 && mode1 != 6)
								{
									myline.color[0] = 200;
									myline.color[1] = 200;
									myline.color[2] = 200;

								}

								lines.push_back(myline);
							}
						}
						else
						{
							if (fft[i] * 1000 > 40)
							{

								Line myline;

								if (i % 3 == 0)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 25, 0, ofRandom(1000, 255), ofRandom(100, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								else if (i % 3 == 1)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 25, -fft[i] * 25, ofRandom(100, 255), ofRandom(0, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								else
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, -fft[i] * 25, ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), fft[i] * 2000, fft[i] * 600, time, 500, mode1);
								}
								if (lineeffectv2count % 2 == 0 && mode1 != 6)
								{
									myline.color[0] = 200;
									myline.color[1] = 200;
									myline.color[2] = 200;

								}

								lines.push_back(myline);
							}
						}
						
					}
				}
				//cout << lineeffectv2count << endl;
				lineeffectv2count++;
				lineeffectv2timing = false;
			}
			else if (ofGetElapsedTimeMillis() % 430 > 350)
			{
				lineeffectv2timing = true;
			}
		}
		for (int i = 0; i < lines.size(); i++)
		{
			if (time > lines[i].life + lines[i].time)
			{
				if (lines[i].mode == 5 )
				{
					movingLine mymovinglines;
					mymovinglines.setup(lines[i].position[0], lines[i].position[1], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time,2);
					movinglines.push_back(mymovinglines);
					lines.erase(lines.begin() + i);
				}
				else if(lines[i].mode == 6|| lines[i].mode == 7)
				{
					/*movingLine mymovinglines;
					mymovinglines.setup(lines[i].position[0], lines[i].position[1], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time);
					movinglines.push_back(mymovinglines);*/
				}
				else if (lines[i].mode == 4)
				{
					Particle myparticle;
					myparticle.setup(lines[i].position[1].x, lines[i].position[1].y, 70*lines[i].velocity.x, 70 * lines[i].velocity.y, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3]);
					myparticle.Radius=lines[i].width;
					lineemitparticles.push_back(myparticle);
					lines.erase(lines.begin() + i);
				}
				else
				{
					lines.erase(lines.begin() + i);
				}
			}
			
			if (mode1 == 7)
			{
				movingLine mymovinglines;
				mymovinglines.setup(lines[i].position[0], lines[i].position[1], 0, ofRandom(0,5)/400, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time,4);
				movinglines.push_back(mymovinglines);
				lines.erase(lines.begin() + i);
			}

		}
		for (int i = 0; i < movinglines.size(); i++)
		{
			movinglines[i].update();
		}
		for (int i = 0; i < movinglines.size(); i++)
		{
			movinglines[i].draw(mode1);
		}
		for (int i = 0; i < movinglines.size(); i++)
		{
			if (movinglines[i].position[0].x > ofGetWidth() || movinglines[i].position[0].x < 0)
			{
				if (movinglines[i].position[1].x > ofGetWidth() || movinglines[i].position[1].x < 0)
				{
					movinglines.erase(movinglines.begin() + i);
				}
			}
		}
		for (int i = 0; i < lines.size(); i++)
		{
			lines[i].update();
		}
		for (int i = 0; i < lines.size(); i++)
		{
			lines[i].draw();
		}
		

		for (int i = 0; i < lineemitparticles.size(); i++)
		{
			lineemitparticles[i].update();
		}
		for (int i = 0; i < lineemitparticles.size(); i++)
		{
			lineemitparticles[i].draw(lineemitparticles[i].Radius);
		}
		for (int i = 0; i < lineemitparticles.size(); i++)
		{
			if (lineemitparticles[i].position.x > ofGetWidth() || lineemitparticles[i].position.x < 0|| lineemitparticles[i].position.y > ofGetHeight() || lineemitparticles[i].position.y < 0)
			{
				
				lineemitparticles.erase(lineemitparticles.begin() + i);
			}
		}
		
	}
	else if (mode1 == 10)
	{
		if (movinglinesreset)
		{
			movinglines.clear();
		}
		if (movinglines.size() > 0)
		{
			movinglinesreset = true;
		}
		else
		{
			movinglinesreset = false;
		}
	}
}

void ofApp::brighttowneffect(int mode)
{
	if (mode == 0)
	{
		if (brighttowns.size() < 10)
		{
			for (int i = 0; i < w[2]; i += 6) {
				for (int j = 0; j < h[2]; j += 4) {
					//ピクセルのRGBの値を取得
					int valueR = pixels[2][j * 3 * w[2] + i * 3];
					int valueG = pixels[2][j * 3 * w[2] + i * 3 + 1];
					int valueB = pixels[2][j * 3 * w[2] + i * 3 + 2];
					if (valueB < 50)
					{
						double kakudai = 2;
						double movedirect = atan(((double)j*ofGetHeight() / h[2] - ofGetHeight() / 2) / ((double)i*ofGetWidth() / w[2] - ofGetWidth() / 2));
						if ((double)i*ofGetWidth() / w[2] - ofGetWidth() / 2 < 0)
						{
							movedirect += M_PI;
						}
						Particle mybrighttown;
						if (ofRandom(0, 3) > 1)
						{
							mybrighttown.setup((double)i*kakudai + (ofGetWidth() / 2 - w[2] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[2] / 2 * kakudai), ofRandom(20, 150) * cos(movedirect) + ((ofRandom(0, 10) - 5)), ofRandom(20, 150) * sin(movedirect) + ((ofRandom(0, 10) - 5)), 0, 0, 0, 0);
						}
						else
						{
							mybrighttown.setup((double)i*kakudai + (ofGetWidth() / 2 - w[2] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[2] / 2 * kakudai),-1* ofRandom(20, 150) * cos(movedirect) + ((ofRandom(0, 10) - 5)), -1*ofRandom(20, 150) * sin(movedirect) + ((ofRandom(0, 10) - 5)), 0, 0, 0, 0);
						}
						brighttowns.push_back(mybrighttown);
					}
				}
			}
		}
	}
	
	double noisex = ofNoise(0, ofGetElapsedTimeMillis());
	double noisey = ofNoise(0, soundvol);
	double m = ofRandom(0, musictime - 8500);
	double n = ofRandom(0, musictime - 8500);
	//double noisey = ofNoise(0, ofGetElapsedTimeMicros());
	if (mode < 10)
	{
		for (int i = 0; i < brighttowns.size(); i++)
		{
			if (mode == 1)
			{
				if (ofRandom(0, musictime - 8500) > 2000)
				{
					brighttowns[i].color[0] = ofRandom(0, 200);
					brighttowns[i].color[1] = ofRandom(0, 200);
					brighttowns[i].color[2] = ofRandom(0, 200);
					brighttowns[i].color[3] = soundvol * 80;

				}
				else
				{
					for (int j = 0; j < 4; j++)
					{
						brighttowns[i].color[j] = soundvol * 60;
					}
				}
				//ノイズによってずれる
				/*if ((musictime - 8500) >2000)
				{
					if (m > 2000)
					{
						if (brighttowns[i].position1.y < ofGetHeight() / 2)
						{
							brighttowns[i].position.x = brighttowns[i].position1.x + (noisex - 0.5) * 200 * (musictime - 8500) / 8000;
						}
					}
					else
					{
						if (brighttowns[i].position1.y < ofGetHeight() / 2)
						{
							brighttowns[i].position.x = brighttowns[i].position1.x;
						}

					}
					if (n > 2000)
					{
						if (brighttowns[i].position1.y> ofGetHeight() / 2)
						{
							brighttowns[i].position.x = brighttowns[i].position1.x + (noisey - 0.5) * 200 * (musictime - 8500) / 8000;
						}
					}
					else
					{
						if (brighttowns[i].position1.y > ofGetHeight() / 2)
						{
							brighttowns[i].position.x = brighttowns[i].position1.x;
						}
					}

				}*/

			}
			else if (mode == 0)
			{
				/*for (int j = 0; j < 3; j++)
				{
					brighttowns[i].color[j] = soundvol * 120;
				}
				brighttowns[i].color[j] = soundvol * 120;*/
				brighttowns[i].color[0] = 200;
				brighttowns[i].color[1] = 200;
				brighttowns[i].color[2] = 200;
				brighttowns[i].color[3] = soundvol * 80;
			}
			else
			{
				brighttowns[i].color[0] = ofRandom(0, 140)*soundvol;
				brighttowns[i].color[1] = ofRandom(0, 140)*soundvol;
				brighttowns[i].color[2] = ofRandom(0, 140)*soundvol;
				brighttowns[i].color[3] = 200 * soundvol;
				brighttowns[i].update();
			}

			if (brighttowns[i].position.x >= 0 && brighttowns[i].position.x <= ofGetWidth() && brighttowns[i].position.y >= 0 && brighttowns[i].position.y <= ofGetHeight())
			{
				brighttowns[i].draw(12);
			}
			else
			{
				brighttowns.erase(brighttowns.begin() + i);
			}
		}
	}
	
}

void ofApp::lineeffectv3(int mode)
{
	if (mode == 8 || mode==7)
	{
		int time = ofGetElapsedTimeMillis();
		//int mode1 = mode - 3;
		if (sxplayelement.size() < 50)
		{
			for (int i = 0; i < 220; i++)
			{
				movingLine element;
				element.setup(sxplaypoint[(int)sxpointline[i % 22].x], sxplaypoint[(int)sxpointline[i % 22].y], ofRandom(0, 240) / 60, ofRandom(0, 30) / 100, ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(100, 255), ofRandom(0, 40), time, 8);
				sxplayelement.push_back(element);

			}

		}
		for (int i = 0; i < sxplayelement.size(); i++)
		{
			sxplayelement[i].update2(4000);
		}
		for (int i = 0; i < sxplayelement.size(); i++)
		{
			sxplayelement[i].draw(mode);
		}
		//cout << sxplayelement.size() << endl;
	}
}

void ofApp::sxplayburst(int mode)
{
	double kakudai = 1.5;
	if (mode < 9)
	{
		if (sxplayparticles.size() < 50)
		{
			for (int i = 0; i < w[0]; i += 4)
			{
				for (int j = 0; j < h[0]; j += 6)
				{
					int valueB = pixels[0][j * 3 * w[0] + i * 3 + 2];
					if (valueB < 70)
					{
						double kakudai = 2;
						double movedirect = atan(((double)j*ofGetHeight() / h[0] - ofGetHeight() / 2) / ((double)i*ofGetWidth() / w[0] - ofGetWidth() / 2));
						if ((double)i*ofGetWidth() / w[0] - ofGetWidth() / 2 < 0)
						{
							movedirect += M_PI;
						}
						Particle myparticles;
						if (ofRandom(0, 3) > 1)
						{
							myparticles.setup((double)i*kakudai + (ofGetWidth() / 2 - w[0] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[0] / 2 * kakudai), ofRandom(20, 150) * cos(movedirect) + ((ofRandom(0, 10) - 5)), ofRandom(20, 150) * sin(movedirect) + ((ofRandom(0, 10) - 5)), ofRandom(0, 250), ofRandom(0, 250), ofRandom(0, 250), 255);
						}
						else
						{
							myparticles.setup((double)i*kakudai + (ofGetWidth() / 2 - w[0] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[0] / 2 * kakudai), -1 * ofRandom(20, 150) * cos(movedirect) + ((ofRandom(0, 10) - 5)), -1 * ofRandom(20, 150) * sin(movedirect) + ((ofRandom(0, 10) - 5)), ofRandom(0, 250), ofRandom(0, 250), ofRandom(0, 250), 255);
						}
						sxplayparticles.push_back(myparticles);
					}
				}
			}
		}
	}
	if (mode == 9|| mode == 10|| mode == 11)
	{
		//cout << sxplayparticles.size() << endl;
		
		ofSetColor(255, 255, 255, sxplayparticles.size() / 10);
		ofSetLineWidth(10);
		for (int i = 0; i < 31; i++)
		{
			
			ofDrawLine(sxplaypoint[(int)sxpointline[i].x], sxplaypoint[(int)sxpointline[i].y]);
		}
		for (int i = 0; i < sxplayparticles.size(); i++)
		{
			sxplayparticles[i].update();
			
		}
		for (int i = 0; i < sxplayparticles.size(); i++)
		{
			if (sxplayparticles[i].position.x >= 0 && sxplayparticles[i].position.x <= ofGetWidth() && sxplayparticles[i].position.y >= 0 && sxplayparticles[i].position.y <= ofGetHeight())
			{
				sxplayparticles[i].draw(mode);
			}
			else
			{
				sxplayparticles.erase(sxplayparticles.begin() + i);
			}
			

		}
		
	}

}
void ofApp::brightingpoint(int mode)
{
	if (mode >8 && mode<18)
	{
		if (brightpoints.size() < 79)
		{
			for (int i = 0; i < 79- brightpoints.size(); i++)
			{
				Particle mypoints;
				double t = ofRandom(0, 360) / 360 * 2 * M_PI;
				mypoints.setup(ofGetWidth() / 2, ofGetHeight() / 2, ofRandom(100, 250)* cos(t)/3, ofRandom(100, 250)* sin(t)/3, ofRandom(0, 250), ofRandom(0, 250), ofRandom(0, 250), ofRandom(0, 250));
				mypoints.distination.x = 0;
				mypoints.distination.y = 0;
				mypoints.Radius = 8;

				mypoints.digree = 2 * M_PI / 360 * ofRandom(0, 360);
				if (mode == 14)
				{
					if (triangles == 0)
					{
						brightpoints.clear();
					}
					mypoints.digree = 0;
					
					mypoints.distination.y =( ofGetHeight() / 12) + ( triangles % 6)*(ofGetHeight() / 6);
					mypoints.distination.x = (ofGetHeight() / 12 / sqrt(3)) + ((triangles - triangles % 6) / 6)*ofGetHeight() / 12 * sqrt(3);
					triangles++;
				}
				if (triangles < 79 && mode!=17 )
				{
					brightpoints.push_back(mypoints);
				}
				
					//cout << brightpoints[0].velocity.x << endl;
				

			}
		}
		if (mode == 16)
		{
			if (triangles > 1)
			{
				for (int i = 0; i < brightpoints.size(); i++)
				{
					double t = atan((brightpoints[i].position.y - ofGetHeight() / 2) / (brightpoints[i].position.x - ofGetWidth() / 2));
					if (brightpoints[i].position.x - ofGetWidth() / 2 < 0)
					{
						t += M_PI;
					}

					brightpoints[i].velocity.x = ofRandom(50, 125)* cos(t) /3;
					brightpoints[i].velocity.y = ofRandom(50, 125)* sin(t) /3;
				}
			}
			triangles = 0;
		}

		if (mode >= 11)
		{
			for (int i = 0; i < brightpoints.size(); i++)
			{
				brightpoints[i].color[4] = fft[(int)ofRandom(0, 120)] * 200;
				brightpoints[i].Radius = fft[(int)ofRandom(0, 120)] * 800;
				for (int j = 0; j < 3; j++)
				{
					brightpoints[i].color[j] = ofRandom(0, 250);
				}
			}
		}
		for (int i = 0; i < brightpoints.size(); i++)
		{
			if (mode == 14|| mode == 15)
			{
				if(brightpoints[i].distination.x==0)
				{
					brightpoints[i].update();
				}
				else
				{
					brightpoints[i].update2();
				}
			}
			else
			{
				brightpoints[i].update();
			}
			
			if (brightpoints[i].position.x >= 0 && brightpoints[i].position.x <= ofGetWidth() && brightpoints[i].position.y >= 0 && brightpoints[i].position.y <= ofGetHeight())
			{
				if (mode==13||mode==14 || mode == 15||mode==16|| mode==17)
				{
					ofNoFill();
					if (mode == 17|| mode == 16)
					{
						if ( fft[(int)ofRandom(0, 100)] * 50> 1.5)
						{
							ofFill();
						}
					}
					ofSetColor(ofRandom(0, 200), ofRandom(0, 200), ofRandom(0, 200), ofRandom(0, 200));
					ofSetLineWidth(ofRandom(0, 120) / 30 * soundvol);
					double r;
					if (brightpoints[i].distination.x == 0)
					{
						r = sqrt((brightpoints[i].position.x - ofGetWidth() / 2)*(brightpoints[i].position.x - ofGetWidth() / 2) + (brightpoints[i].position.y - ofGetHeight() / 2) *(brightpoints[i].position.y - ofGetHeight() / 2)) / 5;
					}
					else
					{
						ofSetColor(ofRandom(0, 200), ofRandom(0, 200), ofRandom(0, 200), ofRandom(0, 150));
						r = ofGetHeight() / 6/sqrt(3);
					}
					
					if (brightpoints[i].distination.x < ofGetWidth())
					{
						//ofSetColor(soundvol * 100, 0, 0, soundvol * 30);
						
						if (mode == 13)
						{
							ofFill();
							r = brightpoints[0].color[i]*1.5;
							ofDrawCircle(ofPoint(brightpoints[i].position.x + r * cos(0 + brightpoints[i].digree), brightpoints[i].position.y + r * sin(0 + brightpoints[i].digree)), brightpoints[i].Radius);
							ofDrawCircle(ofPoint(brightpoints[i].position.x + r * cos(2 * M_PI / 3 * 1 + brightpoints[i].digree), brightpoints[i].position.y + r * sin(2 * M_PI / 3 * 1 + brightpoints[i].digree)), brightpoints[i].Radius);
							ofDrawCircle(ofPoint(brightpoints[i].position.x + r * cos(2 * M_PI / 3 * 2 + brightpoints[i].digree), brightpoints[i].position.y + r * sin(2 * M_PI / 3 * 2 + brightpoints[i].digree)), brightpoints[i].Radius);
							ofNoFill();
						}
						
						if (mode == 15 && fft[(int)ofRandom(0, 100)] * 50> 1.5)
						{
							ofFill();
						}
						if (mode == 13 && ofRandom(0, 100) > 0)
						{
							ofDrawTriangle(ofPoint(brightpoints[i].position.x + r*cos(0 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(0 + brightpoints[i].digree)), ofPoint(brightpoints[i].position.x + r*cos(2 * M_PI / 3 * 1 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(2 * M_PI / 3 * 1 + brightpoints[i].digree)), ofPoint(brightpoints[i].position.x + r*cos(2 * M_PI / 3 * 2 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(2 * M_PI / 3 * 2 + brightpoints[i].digree)));
						}
						else if (mode != 13)
						{
							ofDrawTriangle(ofPoint(brightpoints[i].position.x + r*cos(0 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(0 + brightpoints[i].digree)), ofPoint(brightpoints[i].position.x + r*cos(2 * M_PI / 3 * 1 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(2 * M_PI / 3 * 1 + brightpoints[i].digree)), ofPoint(brightpoints[i].position.x + r*cos(2 * M_PI / 3 * 2 + brightpoints[i].digree), brightpoints[i].position.y + r*sin(2 * M_PI / 3 * 2 + brightpoints[i].digree)));
						}
						
					}
				}
				else
				{
					
					brightpoints[i].draw(brightpoints[i].Radius);
				}
				
			}
			else
			{
				brightpoints.erase(brightpoints.begin() + i);
			}
			
		}
		
		if (mode == 12)
		{
			for (int i = 0; i < brightpoints.size(); i++)
			{
				if (i % 10 ==6)
				{
					if (i % 3 == 0)
					{
						ofSetColor(200, 0, 0, ofRandom(0, 200));
					}
					if (i % 3 == 1)
					{
						ofSetColor(0, 200, 0, ofRandom(0, 200));
					}
					if (i % 3 == 2)
					{
						ofSetColor(0, 0, 200, ofRandom(0, 200));
					}
					ofSetLineWidth(ofRandom(0, 120) / 30 * soundvol);
					ofDrawLine(brightpoints[i].position, brightpoints[i-5].position);
				}
			}
		}
		
	}
}


void ofApp::triangleeffect(int mode)
{
	int time = ofGetElapsedTimeMillis();
	int mode1 = mode ;

	if ((mode1 >= 18 && mode1 <23))
	{
		if (mode1 != 22)
		{
			if (ofGetElapsedTimeMillis() % 425 < 80 && triangleeffecttiming)
			{
				for (int j = 0; j<1; j++)
				{
					for (int i = 0; i < 100; i++)
					{
						if (fft[i] * 1000 > 55)
						{

							Line myline;
							int setmode;
							if (mode1 < 20)
							{
								if (i % 3 == 0)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 30, 0, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
								else if (i % 3 == 1)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 30, -fft[i] * 30, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
								else
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, -fft[i] * 30, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
							}
							else
							{
								if (i % 3 == 0)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 30, 0, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
								else if (i % 3 == 1)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), fft[i] * 30, -fft[i] * 30, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
								else if (i % 3 == 2)
								{
									myline.setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, -fft[i] * 30, ofRandom(0, 255), ofRandom(0, 255 - i), ofRandom(0, 255 - i), fft[i] * 2000, fft[i] * 200, time, 500, mode1);
								}
							}
							if (triangleeffectcount % 2 == 0 && mode1 != 21)
							{
								myline.color[0] = 200;
								myline.color[1] = 200;
								myline.color[2] = 200;

							}

							lines.push_back(myline);
						}
					}
				}
				//cout << lineeffectv2count << endl;
				triangleeffectcount++;
				triangleeffecttiming = false;
			}
			else if (ofGetElapsedTimeMillis() % 425 > 350)
			{
				triangleeffecttiming = true;
			}
		}
		for (int i = 0; i < lines.size(); i++)
		{
			if (time > lines[i].life + lines[i].time)
			{
				if (lines[i].mode == 20)
				{
					movingTriangle mymovingTriangles;
					mymovingTriangles.setup(lines[i].position[0], lines[i].position[1], lines[i].position[3], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time, lines[i].mode);
					movingTriangles.push_back(mymovingTriangles);
					mymovingTriangles.setup(lines[i].position[0], lines[i].position[1], lines[i].position[4], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time, lines[i].mode);
					movingTriangles.push_back(mymovingTriangles);
					lines.erase(lines.begin() + i);
				}
				else if (mode == 22)
				{

				
						movingTriangle mymovingTriangles;
						mymovingTriangles.setup(lines[i].position[0], lines[i].position[1], lines[i].position[3], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time, lines[i].mode);
						movingTriangles.push_back(mymovingTriangles);
						mymovingTriangles.setup(lines[i].position[0], lines[i].position[1], lines[i].position[4], 1.2, 0.005, lines[i].color[0], lines[i].color[1], lines[i].color[2], lines[i].color[3], lines[i].width, time, lines[i].mode);
						movingTriangles.push_back(mymovingTriangles);
						lines.erase(lines.begin() + i);
					

				}
				else if(lines[i].mode != 21)
				{
					lines.erase(lines.begin() + i);
				}

			}

		}
		for (int i = 0; i < movingTriangles.size(); i++)
		{
			if (movingTriangles[i].position[0].x > ofGetWidth() || movingTriangles[i].position[0].x < 0 || movingTriangles[i].position[0].y > ofGetHeight() || movingTriangles[i].position[0].y < 0)
			{
				if (movingTriangles[i].position[1].x > ofGetWidth() || movingTriangles[i].position[1].x < 0 || movingTriangles[i].position[1].y > ofGetHeight() || movingTriangles[i].position[1].y < 0)
				{
					if (movingTriangles[i].position[2].x > ofGetWidth() || movingTriangles[i].position[2].x < 0 || movingTriangles[i].position[2].y > ofGetHeight() || movingTriangles[i].position[2].y < 0)
					{
						movingTriangles.erase(movingTriangles.begin() + i);
					}
				}
			}
		}
		

		for (int i = 0; i < lines.size(); i++)
		{
			lines[i].update();
		}
		for (int i = 0; i < lines.size(); i++)
		{
			lines[i].draw();
		}
		


		for (int i = 0; i <movingTriangles.size(); i++)
		{
			movingTriangles[i].update(mode);
			
		}
		for (int i = 0; i < movingTriangles.size(); i++)
		{
			movingTriangles[i].draw(mode);
		}
	}
	/*else if (mode1 == 25)
	{
		if (movinglinesreset)
		{
			movinglines.clear();
		}
		if (movinglines.size() > 0)
		{
			movinglinesreset = true;
		}
		else
		{
			movinglinesreset = false;
		}
	}*/
}
void ofApp::triangleeffectv2(int mode)
{
	if( mode == 23|| mode == 22)
	{
		if (movingTriangles2.size() < 30)
		{
			for (int i = 0; i < 100; i++)
			{
				movingTriangle mymovingTriangles;
				mymovingTriangles.setup(sxplaypoint[21], ofPoint(sxplaypoint[19].x-3, sxplaypoint[19].y), ofPoint(sxplaypoint[18].x-3, sxplaypoint[18].y-120), 1.2, 0.005, ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(150, 255), 1, ofGetElapsedTimeMillis(), 23);
				movingTriangles2.push_back(mymovingTriangles);
			}
		}


		for (int i = 0; i < movingTriangles2.size(); i++)
		{
			movingTriangles2[i].update2();

		}
		if (mode != 24)
		{
			for (int i = 0; i < movingTriangles2.size(); i++)
			{
				movingTriangles2[i].draw(mode);


			}
		}
		int c = 0;
		for (int i = 0; i < movingTriangles2.size(); i++)
		{
			if (movingTriangles2[i].time2 < (ofGetElapsedTimeMillis() - movingTriangles2[i].time))
			{
				c++;
			}
		}
	
			ofSetColor(c*2.5, c*2.5, c*2.5, c*2.5);

			ofSetLineWidth(10);
			for (int i = 0; i < 22; i++)
			{
				ofDrawLine(sxplaypoint[(int)sxpointline[i].x], sxplaypoint[(int)sxpointline[i].y]);
			}
		
	}
}

void ofApp::triangleburst(int mode)
{
	if (mode >= 24&&mode<32)
	{
		if (movingTriangles3.size() < 8)
		{
			for (int i = 0; i < 300; i++)
			{
				double colorR, colorG, colorB;

				if (i < 100)
				{
					colorR = (double)255 / 100 * (double)i;
					colorG = 0;
					colorB = (double)255 - 255 / 100 * (double)i;
				}
				else if (i < 200)
				{
					colorR = (double)510 - 255 / 100 * (double)i;
					colorG = (double)255 / 100 * (double)i - 255;
					colorB = 0;
				}
				else
				{
					colorR = 0;
					colorG = (double)765 - 255 / 100 * (double)i;
					colorB = (double)255 / 100 * (double)i - 510;
				}
				//colorR = 0; colorG = 0; colorB = 255;
				movingTriangle mymovingTriangles;
				mymovingTriangles.setup(ofPoint(0, 0), ofPoint(0, 0), ofPoint(0, 0), i, i, colorR, colorG, colorB, 30, 1, ofGetElapsedTimeMillis(), 24);
				movingTriangles3.push_back(mymovingTriangles);
			}
		}
		if (mode == 24 || mode == 25 ||mode==26)
		{
			if (movingTriangles4.size() < 25)
			{
				for (int i = 0; i < (25 - movingTriangles4.size()); i++)
				{
					movingTriangle mymovingTriangles;
					mymovingTriangles.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2), ofPoint(0, 0), ofPoint(0, 0),3* i, i, ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 100, 1, ofGetElapsedTimeMillis(), 25);
					movingTriangles4.push_back(mymovingTriangles);
				}
			}
		}
		else if (mode == 29)
		{
			double  colornumber = 0;
			if (musictime > 144000 && musictime < 145200)
			{
				colornumber = 1;
			}
			else if (musictime > 147500 && musictime < 148700)
			{
				colornumber = 2;
			}
			else if (musictime > 150800 && musictime < 152000)
			{
				colornumber = 3;
			}
			else if (musictime > 154200 && musictime < 155400)
			{
				colornumber = 4;
			}
			else if (musictime > 157600 && musictime < 158800)
			{
				colornumber = 5;
			}
			else if (musictime > 161000 && musictime < 162200)
			{
				colornumber = 6;
			}
			else if (musictime > 164400 && musictime < 165600)
			{
				colornumber = 7;
			}
			else if (musictime > 167800 && musictime < 169000)
			{
				colornumber = 8;
			}

			double colorR, colorG, colorB;
			if (colornumber != 0)
			{
				colornumber *= (double)(400 / 8);
				//colornumber = 350;
				if (colornumber < 100)
				{
					colorB = (double)255 / 100 * (double)colornumber;
					colorG = 0;
					colorR = (double)255 - 255 / 100 * (double)colornumber;
				}
				else if (colornumber < 200)
				{
					colorB = (double)510 - 255 / 100 * (double)colornumber;
					colorG = (double)255 / 100 * (double)colornumber - 255;
					colorR = 0;
				}
				else
				{
					colorB = 0;
					colorG = (double)765 - 255 / 100 * (double)colornumber;
					colorR = (double)255 / 100 * (double)colornumber - 510;
				}
				if (movingTriangles4.size() < 120)
				{
					for (int i = 0; i < (120 - movingTriangles4.size()); i++)
					{
						movingTriangle mymovingTriangles;
						mymovingTriangles.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2), ofPoint(0, 0), ofPoint(0, 0), 3 * i, i, colorR, colorG, colorB, 120, 1, ofGetElapsedTimeMillis(), 29);
						movingTriangles4.push_back(mymovingTriangles);
					}
				}
			}
		}
		for (int i = 0; i < movingTriangles4.size(); i++)
		{
			movingTriangles4[i].update(mode);
		}
		for (int i = 0; i < movingTriangles4.size(); i++)
		{
			if (movingTriangles4[i].position[0].x > ofGetWidth() || movingTriangles4[i].position[0].x < 0 || movingTriangles4[i].position[0].y > ofGetHeight() || movingTriangles4[i].position[0].y < 0)
			{
				if (movingTriangles4[i].position[1].x > ofGetWidth() || movingTriangles4[i].position[1].x < 0 || movingTriangles4[i].position[1].y > ofGetHeight() || movingTriangles4[i].position[1].y < 0)
				{
					if (movingTriangles4[i].position[2].x > ofGetWidth() || movingTriangles4[i].position[2].x < 0 || movingTriangles4[i].position[2].y > ofGetHeight() || movingTriangles4[i].position[2].y < 0)
					{
						movingTriangles4.erase(movingTriangles4.begin() + i);
					}
				}
			}
		}
		for (int i = 0; i < movingTriangles4.size(); i++)
		{
			movingTriangles4[i].draw(mode);
		}
		

		for (int i = 0; i < movingTriangles3.size(); i++)
		{
			movingTriangles3[i].update(mode);
			
		}
		for (int i = 0; i < movingTriangles3.size(); i++)
		{

			if (mode >= 30)
			{
				
				emittingtime2 = musictime - emittingtime3;
				if (emittingtime2 < 3500)
				{
					emittingtime2 = (double)((emittingtime2) % 3500) / 350 * 30;

					if (i > emittingtime2&&i < 150)
					{
						movingTriangles3[i].draw(mode);
					}
					else if (i > emittingtime2 + 150 && i >= 150)
					{
						movingTriangles3[i].draw(mode);
					}
					
				}
				//cout << emittingtime2 << endl;
			}
			else
			{
				movingTriangles3[i].draw(mode);
			}
			if(mode == 26)
			{
				ofSetLineWidth(10);
				ofSetColor(movingTriangles3[i].color[0], movingTriangles3[i].color[1], movingTriangles3[i].color[2], 80);
				double t = ((int)ofGetElapsedTimeMillis / 100) % 300 - 150;
				t = t / 360 * 2 * M_PI;
				if (ofRandom(0, 1000)<50)
				{
					for (int c = 0; c < 3; c++)
					{
						double dig = atan((movingTriangles3[i].position[c].y - movingTriangles3[i].center.y) / (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x));
						if (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x < 0)
						{
							dig += M_PI;
						}
						ofDrawLine(movingTriangles3[i].position[c], ofVec2f(movingTriangles3[i].position[c].x + 1000 * cos(dig), movingTriangles3[i].position[c].y + 1000 * sin(dig )));
					}

				}
				//cout << liningtime <<" "<< ofGetElapsedTimeMillis() <<" "<< liningtime1 << endl;
			}
			else if (mode == 27)
			{
				/*double t = ((int)ofGetElapsedTimeMillis / 100) % 300 - 150;
				t = t / 360 * 2 * M_PI;*/
			
				if (movinglines2.size() < 300)
				{
					if (ofRandom(0, 1000) < 40)
					{
						int c = i % 3;
						double dig = atan((movingTriangles3[i].position[c].y - movingTriangles3[i].center.y) / (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x));
						if (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x < 0)
						{
							dig += M_PI;
						}
						//ofDrawLine(movingTriangles3[i].position[c], ofVec2f(movingTriangles3[i].position[c].x + 1000 * cos( dig), movingTriangles3[i].position[c].y + 1000 * sin( dig)));

						double l = ofRandom(50, 200);
						movingLine myline;
						myline.setup(movingTriangles3[i].position[c], ofVec2f(movingTriangles3[i].position[c].x + l * cos(dig), movingTriangles3[i].position[c].y + l* sin(dig)), ofRandom(50, 200) / 200, 0, movingTriangles3[i].color[0], movingTriangles3[i].color[1], movingTriangles3[i].color[2], 60, 10, time, 27);
						movinglines2.push_back(myline);

					}


				}
				//cout << liningtime <<" "<< ofGetElapsedTimeMillis() <<" "<< liningtime1 << endl;
			}
			else if (mode == 28)
			{
				ofSetLineWidth(10);
				ofSetColor(movingTriangles3[i].color[0], movingTriangles3[i].color[1], movingTriangles3[i].color[2], 50);
				double t = ((int)ofGetElapsedTimeMillis / 100) % 300 - 150;
				t = t / 360 * 2 * M_PI;
				
				if (i%5==0)
				{
					for (int c = 0; c < 3; c++)
					{
						double dig = atan((movingTriangles3[i].position[c].y - movingTriangles3[i].center.y) / (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x));
						if (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x < 0)
						{
							dig += M_PI;
						}
						ofDrawLine(movingTriangles3[i].position[c], ofVec2f(movingTriangles3[i].position[c].x + 1000 * cos(dig + t), movingTriangles3[i].position[c].y + 1000 * sin(dig + t)));
					}
				}
				
				//cout << liningtime <<" "<< ofGetElapsedTimeMillis() <<" "<< liningtime1 << endl;
			}
			else if (mode == 29)
			{
				kosa -=0.002;
				if (kosa > 5)
				{
					ofSetLineWidth(10);
					ofSetColor(movingTriangles3[i].color[0], movingTriangles3[i].color[1], movingTriangles3[i].color[2], kosa);
					double t = ((int)ofGetElapsedTimeMillis / 100) % 300 - 150;
					t = t / 360 * 2 * M_PI;

					if (i%5==0)
					{
						for (int c = 0; c < 3; c++)
						{
							double dig = atan((movingTriangles3[i].position[c].y - movingTriangles3[i].center.y) / (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x));
							if (movingTriangles3[i].position[c].x - movingTriangles3[i].center.x < 0)
							{
								dig += M_PI;
							}
							ofDrawLine(movingTriangles3[i].position[c], ofVec2f(movingTriangles3[i].position[c].x + 1000 * cos(dig + t), movingTriangles3[i].position[c].y + 1000 * sin(dig + t)));
						}
					}
					//cout << "a" << endl;
				}
				

				//cout << liningtime <<" "<< ofGetElapsedTimeMillis() <<" "<< liningtime1 << endl;
			}


		}
		/*for (int i = 0; i < 22; i++)
		{
			ofSetLineWidth(10);
			ofSetColor(255, 255, 255, 255);
			ofDrawLine(sxplaypoint[(int)sxpointline[i].x], sxplaypoint[(int)sxpointline[i].y]);
		}*/

		for (int i = 0; i < movinglines2.size(); i++)
		{
			movinglines2[i].update();
		}
		for (int i = 0; i < movinglines2.size(); i++)
		{
			if (movinglines2[i].position[2].x > ofGetWidth() || movinglines2[i].position[2].x < 0)
			{
				if (movinglines2[i].position[2].y > ofGetHeight() || movinglines2[i].position[2].y < 0)
				{
					movinglines2.erase(movinglines2.begin() + i);
				}
			}
		}
		
		for (int i = 0; i < movinglines2.size(); i++)
		{
			movinglines2[i].draw(mode);
			//cout << movinglines2.size() << endl;
		}

	}
}


void ofApp::triangleemitter(int mode)
{
	if (mode == 29 || mode==30)
	{
		for (int j = 0; j < 2; j++)
		{
			if (mode<30)
			{
				emittingtime = musictime - emittingtime1;
				emittingtime = (double)((emittingtime + 875 * j) % 1750) / 175 * 30;
				emitcenter[j].x = ofGetWidth() / 2 + 600 * cos((double)emittingtime / 300 * 2 * M_PI);
				emitcenter[j].y = ofGetHeight() / 2 + 600 * sin((double)emittingtime / 300 * 2 * M_PI);
			}
			else if(mode == 30)
			{
				emittingtime2 = musictime - emittingtime3;
				if (emittingtime2 < 3500)
				{
					
					emittingtime2 = (double)((emittingtime2 + 1750 * j) % 3500) / 350 * 30;
					emitcenter[j].x = ofGetWidth() / 2 + 600 * cos((double)emittingtime2 / 300 * 2 * M_PI);
					emitcenter[j].y = ofGetHeight() / 2 + 600 * sin((double)emittingtime2 / 300 * 2 * M_PI);
				}
				else
				{
					emittingtime2 = (double)((emittingtime2 + 1750* j) % 3500) / 350 * 30;
					emitcenter[j].x = ofGetWidth() / 2 + infinitR*2 * cos((double)emittingtime2 / 300 * 2 * M_PI);
					
					
					if (j == 1)
					{
						emitcenter[j].y = ofGetHeight() / 2 - infinitR * sin((double)emittingtime2 / 300 * 2 * M_PI * 2);
					}
					else
					{
						emitcenter[j].y = ofGetHeight() / 2 + infinitR * sin((double)emittingtime2 / 300 * 2 * M_PI * 2);
					}
					infinitR += 1;
					//cout << emittingtime2 << endl;
				}
			}
			
			
			//ofDrawCircle(emitcenter[j], 200);
			emitvelocity[j] =  emitcenterold[j]-emitcenter[j];
			emitvelocitydigree[j] = atan(emitvelocity[j].y / emitvelocity[j].x);
			if (emitvelocity[j].x < 0)
			{
				emitvelocitydigree[j] += M_PI;
			}
			//ofSetLineWidth(10);
			//ofDrawLine(emitcenter[j], emitcenter[j] + emitvelocity[j] * 100);
			//cout << emittingtime <<" "<< emitvelocity[j].x<<" "<< emitvelocity[j].y<<endl;
			if (mode == 29)
			{
				for (int i = 0; i < 4; i++)
				{
					double colorR, colorG, colorB;
					if (mode == 30)
					{
						emittingtime = 0 + j * 150;
					}
					//emittingtime = 100;
					if (emittingtime < 100)
					{
						colorR = 255 / 100 * emittingtime;
						colorG = 0;
						colorB = 255 - 255 / 100 * emittingtime;
					}
					else if (emittingtime < 200)
					{
						colorR = 510 - 255 / 100 * emittingtime;
						colorG = 255 / 100 * emittingtime - 255;
						colorB = 0;
					}
					else
					{
						colorR = 0;
						colorG = 765 - 255 / 100 * emittingtime;
						colorB = 255 / 100 * emittingtime - 510;
					}
					double r = 100;
					movingTriangle2 myTriangles;
					emitvelocity[j].x = r*cos(emitvelocitydigree[j] + (ofRandom(0, 90) - 45) / 180 * M_PI);
					emitvelocity[j].y = r*sin(emitvelocitydigree[j] + (ofRandom(0, 90) - 45) / 180 * M_PI);
					myTriangles.setup(emitcenter[j], emitvelocity[j], ofRandom(0, 10) / 10, colorR, colorG, colorB, 90, 1, ofGetElapsedTimeMillis(), 1000);
					emittingTriangles[j].push_back(myTriangles);
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
				{
					double colorR, colorG, colorB;
					if (mode == 30)
					{
						emittingtime = 0 + j * 150;
					}
					//emittingtime = 100;
					if (emittingtime < 100)
					{
						colorR = 255 / 100 * emittingtime;
						colorG = 0;
						colorB = 255 - 255 / 100 * emittingtime;
					}
					else if (emittingtime < 200)
					{
						colorR = 510 - 255 / 100 * emittingtime;
						colorG = 255 / 100 * emittingtime - 255;
						colorB = 0;
					}
					else
					{
						colorR = 0;
						colorG = 765 - 255 / 100 * emittingtime;
						colorB = 255 / 100 * emittingtime - 510;
					}
					double r = 100;
					movingTriangle2 myTriangles;
					emitvelocity[j].x = r*cos(emitvelocitydigree[j] + (ofRandom(0, 90) - 45) / 180 * M_PI);
					emitvelocity[j].y = r*sin(emitvelocitydigree[j] + (ofRandom(0, 90) - 45) / 180 * M_PI);
					myTriangles.setup(emitcenter[j], emitvelocity[j], ofRandom(0, 10) / 10, colorR, colorG, colorB, 100, 1, ofGetElapsedTimeMillis(), 1000);
					emittingTriangles[j].push_back(myTriangles);
				}
			}
			emitcenterold[j] = emitcenter[j];
			
			for (int i = 0; i < emittingTriangles[j].size(); i++)
			{
				if (ofGetElapsedTimeMillis() > emittingTriangles[j][i].time + emittingTriangles[j][i].life)
				{
					emittingTriangles[j].erase(emittingTriangles[j].begin() + i);
				}
			}
			for (int i = 0; i < emittingTriangles[j].size(); i++)
			{
				if (emittingTriangles[j][i].position[0].x > ofGetWidth() || emittingTriangles[j][i].position[0].x < 0 || emittingTriangles[j][i].position[0].y > ofGetHeight() || emittingTriangles[j][i].position[0].y < 0)
				{
					if (emittingTriangles[j][i].position[1].x > ofGetWidth() || emittingTriangles[j][i].position[1].x < 0 || emittingTriangles[j][i].position[1].y > ofGetHeight() || emittingTriangles[j][i].position[1].y < 0)
					{
						if (emittingTriangles[j][i].position[2].x > ofGetWidth() || emittingTriangles[j][i].position[2].x < 0 || emittingTriangles[j][i].position[2].y > ofGetHeight() || emittingTriangles[j][i].position[2].y < 0)
						{
							emittingTriangles[j].erase(emittingTriangles[j].begin() + i);
						}
					}
				}
			}
			for (int i = 0; i < emittingTriangles[j].size(); i++)
			{
				emittingTriangles[j][i].update();
				//cout << particles[i].velocity.x << endl;
			}
			for (int i = 0; i < emittingTriangles[j].size(); i++)
			{
				emittingTriangles[j][i].draw();
				//cout << particles[i].velocity.x << endl;
			}
			
		}
		
	}
}


void ofApp::infiniteburst(int mode)
{
	if (mode >= 30)
	{
		if (mode == 30)
		{
			if (burstTriangles.size() < 40)
			{
				for (int i = 0; i < 500; i++)
				{
					int c;
					double colorR, colorG, colorB;
					if (ofRandom(0, 100) < 50)
					{
						c = 0;
					}
					else
					{
						c = 150;
					}
					if (c < 100)
					{
						colorR = 255 / 100 * c;
						colorG = 0;
						colorB = 255 - 255 / 100 * c;
					}
					else if (c < 200)
					{
						colorR = 510 - 255 / 100 * c;
						colorG = 255 / 100 * c - 255;
						colorB = 0;
					}
					else
					{
						colorR = 0;
						colorG = 765 - 255 / 100 * c;
						colorB = 255 / 100 * c - 510;
					}
					movingTriangle mymovingTriangles;
					mymovingTriangles.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2), ofPoint(0, 0), ofPoint(0, 0), i, i, colorR, colorG, colorB, 100, 1, ofGetElapsedTimeMillis(), 25);
					burstTriangles.push_back(mymovingTriangles);
				}
			}
		}
		else
		{
			for (int i = 0; i < burstTriangles.size(); i++)
			{
				if (burstTriangles[i].position[0].x > ofGetWidth() || burstTriangles[i].position[0].x < 0 || burstTriangles[i].position[0].y > ofGetHeight() || burstTriangles[i].position[0].y < 0)
				{
					if (burstTriangles[i].position[1].x > ofGetWidth() || burstTriangles[i].position[1].x < 0 || burstTriangles[i].position[1].y > ofGetHeight() || burstTriangles[i].position[1].y < 0)
					{
						if (burstTriangles[i].position[2].x > ofGetWidth() || burstTriangles[i].position[2].x < 0 || burstTriangles[i].position[2].y > ofGetHeight() || burstTriangles[i].position[2].y < 0)
						{
							burstTriangles.erase(burstTriangles.begin() + i);
						}
					}
				}
			}
			for (int i = 0; i < burstTriangles.size(); i++)
			{
				burstTriangles[i].update(mode);
				//cout << particles[i].velocity.x << endl;
			}
			for (int i = 0; i < burstTriangles.size(); i++)
			{
				burstTriangles[i].draw(mode);
				//cout << particles[i].velocity.x << endl;
			}

		}
	}
}

void ofApp::throughsxplay(int mode1)
{
	if (mode1 == 24|| mode1 == 25)
	{
		for (int i = 0; i < 31; i++)
		{
			
			sxplayL[i] *= (1+((double)(musictime - sxplaytime) / 2000));
			
			
			sxplaypoint2[i] = ofPoint(sxplayL[i] *cos(sxplayDig[i]) + ofGetWidth()/2, sxplayL[i] *sin(sxplayDig[i]) + ofGetHeight()/2);
		}
		for (int i = 0; i < 22; i++)
		{
			ofSetLineWidth(200);
			ofSetColor(255, 255, 255, 255);
			ofDrawLine(sxplaypoint2[(int)sxpointline[i].x], sxplaypoint2[(int)sxpointline[i].y]);
		}
	}
}
void ofApp::commingparticle(int mode1)
{
	if (mode1 == 32)
	{
		double L;
		for (int i = 0; i < 4; i++)
		{
			L = 1;
			double T1 = ofRandom(65, 89) / 360 * 2 * M_PI;
			double T2 = ofRandom(0, 360) / 360 * 2 * M_PI;

			Particle3d myparticle;
			myparticle.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, -10000), ofVec3f(L*cos(T1)*cos(T2), L*cos(T1)*sin(T2), L*sin(T1)), 255, 255, 255, 0, time);
			particles3d.push_back(myparticle);

		}
		L = 230;
		
		for (int i = 0; i < particles3d.size(); i++)
		{
			particles3d[i].update2(L);
		}
		for (int i = 0; i < particles3d.size(); i++)
		{
			if (particles3d[i].position.x > ofGetWidth() || particles3d[i].position.x < 0)
			{
				if (particles3d[i].position.y > ofGetHeight() || particles3d[i].position.y < 0)
				{
					particles3d.erase(particles3d.begin() + i);
				}
			}
		}
		for (int i = 0; i < particles3d.size(); i++)
		{
			particles3d[i].draw(20);
		}
		//cout << particles3d.size() << endl;
	}
}
void ofApp::commingparticle2(int mode1)
{
	if (mode1 == 33|| mode1 == 34 || mode1 == 35|| mode1 == 36 || mode1 == 37 || mode1 == 38|| mode1 == 39 || mode1 == 40)
	{
		
		double L2 ;
		double T1;
		double T2;
		double T3 ;
		double dig;
		if (mode1 != 39&& mode1!=40)
		{
			dig = (double)(musictime - commingparticle2time) / 40;
			if (dig > 95)
			{
				dig = 95;
			}
		}
		else
		{
			dig = 95-(double)(musictime - commingparticle2time) / 80;
			if (dig < 0)
			{
				dig = 0;
			}
		}
		//L = 1;
		int x = 0;
		if ((mode1 == 39|| mode1==40)&& musictime - commingparticle2time >10500)
		{
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				double L3 = 1;
				// ofRandom(10, 30);
				L2 = 10000;
				T1 = ofRandom(65, 89) / 360 * 2 * M_PI;
				T2 = ofRandom(0, 360) / 360 * 2 * M_PI;
				T3 = -(double)dig / 360 * 2 * M_PI;
				Particle3d myparticle;
				myparticle.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2 + L2*sin(T3), -L2*cos(T3)), ofVec3f(L3*cos(T1)*cos(T2), L3*cos(T1)*sin(T2)*cos(T3) - L3*sin(T1)*sin(T3), L3*cos(T1)*sin(T2)*sin(T3) + L3*sin(T1)*cos(T3)), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 0, time);
				particles3d.push_back(myparticle);

			}
		}
		if (musictime < 196100)
		{
			
			particlespeed = 230;
		}
		else if (musictime > 195000 && musictime < 198813)
		{
			particlespeed -=4;
			if (particlespeed < 5)
			{
				particlespeed = 5;
			}
			//cout << particlespeed << endl;
		}
		else if (musictime > 198813)
		{
			particlespeed += 8;
			if (particlespeed > 230)
			{
				particlespeed = 230;
			}
		}
		//L2 = 25000;
		
		//ofSetLineWidth(10);
		//ofDrawLine(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2 + L2*sin(T3), -L2*cos(T3)), ofPoint(ofGetWidth() / 2 + 1000*cos(T1)*cos(T2), ofGetHeight() / 2 + 1000*cos(T1)*sin(T2)*cos(T3) - 1000*sin(T1)*sin(T3), 1000*cos(T1)*sin(T2)*sin(T3) + 1000*sin(T1)*cos(T3)));
		//cout << L2*sin(T3) << endl;
		for (int i = 0; i < particles3d.size(); i++)
		{
			particles3d[i].update2(particlespeed);
		}

		for (int i = 0; i < particles3d.size(); i++)
		{
			if (particles3d[i].position.x > ofGetWidth() || particles3d[i].position.x < 0)
			{
				if (particles3d[i].position.y > ofGetHeight())
				{
					particles3d.erase(particles3d.begin() + i);
				}
			}
		}

		for (int i = 0; i < particles3d.size(); i++)
		{
			particles3d[i].draw(20);
		}
		//cout << particles3d.size() << endl;
	}
}
void ofApp::rollingbox(int mode1)
{
	if (mode1 == 34|| mode1 == 35|| mode1 == 36)
	{
		if (mode1 != 36)
		{
			if (ofRandom(0, 1000) < 100)
			{
				ofBoxPrimitive mybox;
				mybox.set(100, 100 , 100, 2,2,2);
				boxes.push_back(mybox);

				controlbox mybox2;
				mybox2.setup(ofRandom(0, 1000) - 500, 0.002,  ofRandom(0, 500) - 250, ofRandom(500, 1000), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 180, time);


				controlboxes.push_back(mybox2);

			}
		}
		
		for (int i = 0; i < controlboxes.size(); i++)
		{
			if (controlboxes[i].digree > 2*M_PI)
			{
				controlboxes.erase(controlboxes.begin() + i);
				boxes.erase(boxes.begin() + i);
				
			}

		}
		for (int i = 0; i < controlboxes.size(); i++)
		{
			controlboxes[i].update(mode1);
			if (mode1 != 34)
			{
				for (int j = 0; j < 3; j++)
				{
					controlboxes[i].color[j] = ofRandom(0, 255);
				}
			}
		}
		//cout << controlboxes.size() << " " << boxes.size() << endl;
		for (int i = 0; i < controlboxes.size(); i++)
		{
			controlboxes[i].draw();
			boxes[i].setPosition(controlboxes[i].position);
			boxes[i].rotate(3, 0, 1, 0);
			boxes[i].rotate(3, 1, 0, 0);

			boxes[i].drawWireframe();
		}
		

	}
}
void ofApp::downcylinder(int mode1)
{
	if (mode1 == 34 || mode1 == 35 || mode1 == 36|| mode1 == 37)
	{
		if (mode1 != 37)
		{
			if (musictime%500<100&& cy==true)
			{
				ofCylinderPrimitive mycylinder;
				mycylinder.set(10000, 4000, 40, 3, 0);
				cylinders.push_back(mycylinder);

				controlcylinder mycylinder2;
				mycylinder2.setup(40, ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 80, time);


				controlcylinders.push_back(mycylinder2);
				cy = false;

			}
			else if (musictime % 500>400)
			{
				cy = true;
			}
		}

		for (int i = 0; i < controlcylinders.size(); i++)
		{
			if (controlcylinders[i].position.y>ofGetHeight()*3)
			{
				controlcylinders.erase(controlcylinders.begin() + i);
				cylinders.erase(cylinders.begin() + i);

			}

		}
		for (int i = 0; i < controlcylinders.size(); i++)
		{

			controlcylinders[i].update();
		}
		//cout << controlboxes.size() << " " << boxes.size() << endl;
		for (int i = 0; i < controlcylinders.size(); i++)
		{
			controlcylinders[i].draw();
			cylinders[i].setPosition(controlcylinders[i].position);
			cylinders[i].rotate(3, 0, 1, 0);
			
			cylinders[i].drawWireframe();
		}


	}
}
void ofApp::rollingtriangle(int mode1)
{
	if (mode1 == 36||mode1 == 37)
	{
		int triangles = 0;
		if (rollTriangles.size() < 10)
		{
			for (int i = 0; i < 36; i++)
			{
				rollTriangle mytriangle;
				mytriangle.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0), ofPoint(ofGetWidth() / 2 +100+ (-6+(triangles - triangles % 6)/6 )*ofGetHeight() / 12 * sqrt(3), (ofGetHeight() / 12) + (triangles % 6)*(ofGetHeight() / 6), 0),musictime);
				triangles++;
				rollTriangles.push_back(mytriangle);
			}
			triangles = 0;
			for (int i = 0; i < 36; i++)
			{
				rollTriangle mytriangle;
				mytriangle.setup(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0), ofPoint(ofGetWidth() / 2 - 100+(6 - (triangles - triangles % 6) / 6)*ofGetHeight() / 12 * sqrt(3), (ofGetHeight() / 12) + (triangles % 6)*(ofGetHeight() / 6), 0),musictime);
				triangles++;
				rollTriangles.push_back(mytriangle);
			}
		}
		 
		for (int i = 0; i < rollTriangles.size(); i++)
		{
			if (musictime - rollingtime < 1500)
			{
				rollTriangles[i].update();
			}
			else if(musictime - rollingtime < 3000)
			{
				rollTriangles[i].update2(musictime);
			}
			else if (musictime - rollingtime < 4500)
			{
				rollTriangles[i].update3(musictime);
			}
			else if (musictime - rollingtime < 6000)
			{
				rollTriangles[i].distination=ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0);
				rollTriangles[i].update();
			}
		}
		if (musictime - rollingtime >= 6000)
		{
			if (rollTriangles.size() > 5)
			{
				for (int i = 0; i < rollTriangles.size(); i++)
				{
					rollTriangles.clear();
				}
			}
			bigtriangleR = (0 - bigtriangleR) / 50 + bigtriangleR;
			if (bigtriangleR > 30)
			{
				ofSetColor(255., 255, 255, bigtriangleR*2.5);
				ofDrawTriangle(ofPoint(ofGetWidth() / 2 + bigtriangleR*cos(0), ofGetHeight() / 2 + bigtriangleR*sin(0), 0), ofPoint(ofGetWidth() / 2 + bigtriangleR*cos(2 * M_PI / 3), ofGetHeight() / 2 + bigtriangleR*sin(2 * M_PI / 3), 0), ofPoint(ofGetWidth() / 2 + bigtriangleR*cos(-2 * M_PI / 3), ofGetHeight() / 2 + bigtriangleR*sin(-2 * M_PI / 3), 0));
			}
		}
		else
		{
			for (int i = 0; i < rollTriangles.size(); i++)
			{
				rollTriangles[i].draw(musictime);
			}
		}
	}
}

void ofApp::pointeffect(int mode1)
{
	if (mode1 == 37||mode1==38|| mode1 == 39)
	{
		if (movingpoints.size() == 0)
		{
			movingpoint mypoint;
			mypoint.setup(ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255), 250, 0, musictime);
			movingpoints.push_back(mypoint);
			mypoint.setup(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 250, 1, musictime);
			movingpoints.push_back(mypoint);

			for (int i = 0; i < 24; i++)
			{
				ofSpherePrimitive mysphere;
				mysphere.set(20, 10);
				spheres.push_back(mysphere);
				mysphere.set(20, 10);
				spheres.push_back(mysphere);
				mysphere.set(20, 10);
				spheres.push_back(mysphere);
			}
		}
		else if (movingpoints.size() < 24)
		{
			if (movingpoints[0].digree > (double)(movingpoints.size() / 2) * 2 * M_PI / 12)
			{
				movingpoint mypoint;
				mypoint.setup(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 250, 0, musictime);
				mypoint.digree1 = movingpoints[0].digree - (double)(movingpoints.size() / 2) * 2 * M_PI / 12;
				mypoint.digree = movingpoints[0].digree - (int)(movingpoints.size() / 2) * 2 * M_PI / 12*0;
				movingpoints.push_back(mypoint);
				mypoint.setup(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 250, 1, musictime);
				mypoint.digree = movingpoints[0].digree - (int)((movingpoints.size()-1) / 2) * 2 * M_PI / 12*0;
				//mypoint.digree1 = movingpoints[0].digree - (double)(movingpoints.size() / 2) * 2 * M_PI / 12;
				movingpoints.push_back(mypoint);
			}
		}
		else if (movingpoints.size() >=24)//ボール勢ぞろい
		{
			if (linepoints.size() < 10)
			{
				for (int i = 0; i < 24; i++)
				{
					linepoint mypoint;
					mypoint.setup( movingpoints[i].position[0], movingpoints[i].color[0], movingpoints[i].color[1], movingpoints[i].color[2], movingpoints[i].color[3], movingpoints[i].mode, musictime);
					linepoints.push_back(mypoint);
					
				}
			}
			
		}
		for (int i = 0; i < movingpoints.size(); i++)
		{
			if (i == 0 || i == 1)
			{
				movingpoints[i].digree = 0.0025*(double)(musictime - movingpoints[0].time);
			}
			else
			{
				movingpoints[i].digree =movingpoints[0].digree - (int)(i / 2) * 2 * M_PI / 12 ;
			}
			movingpoints[i].update(musictime);
		}
		if (movingpoints.size() < 24)
		{
			for (int i = 0; i < movingpoints.size(); i++)
			{
				ofSetColor(255, 255, 255, 255);
				spheres[i].setPosition(movingpoints[i].position[1]);
				spheres[i].draw();
			}
		}
		else//ボールが勢ぞろいした後
		{
			for (int i = 0;  i < linepoints.size(); i++)
			{
				linepoints[i].renewpoint(movingpoints[i].position[1]);
			}
			for (int i = 0;  i < linepoints.size(); i++)
			{
				linepoints[i].update(modelinepoints);
			}
			for (int i = 0;  i < linepoints.size();i++)
			{
				if (modelinepoints >= 4)
				{
					ofSetColor(linepoints[i].color[0], linepoints[i].color[1], linepoints[i].color[2], linepoints[i].color[3]);

					ofSetLineWidth(10);
					ofDrawTriangle(linepoints[i].position[1], linepoints[i].position[2], linepoints[i].position[3]);
					
					//cout << "a" << endl;
					spheres[3 * i].setPosition(linepoints[i].position[1]);
					spheres[3 * i].draw();
					spheres[3 * i + 1].setPosition(linepoints[i].position[2]);
					spheres[3 * i + 1].draw();
					spheres[3 * i + 2].setPosition(linepoints[i].position[3]);
					spheres[3 * i + 2].draw();
				}
				else
				{
					ofSetColor(255, 255, 255, linepoints[i].color[3]);

					ofSetLineWidth(10);
					ofDrawLine(linepoints[i].position[1], linepoints[i].position[2]);
					//cout << "a" << endl;
					spheres[2 * i].setPosition(linepoints[i].position[1]);
					spheres[2 * i].draw();
					spheres[2 * i + 1].setPosition(linepoints[i].position[2]);
					spheres[2 * i + 1].draw();
				}
				
			}
			if (modelinepoints == 0)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (linepoints[i].lineLength > 1000)
					{
						modelinepoints = 1;
						linepoints[i].lineLength = 0;
					}
				}
				
			}
			else if (modelinepoints == 1)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (linepoints[i].mode == 1)
					{
						if (linepoints[i].digree > 180)
						{
							modelinepoints = 2;
							linepoints[i].digree = 0;
						}
					}
					else if (linepoints[i].mode == 0)
					{
						if (linepoints[i].digree < -180)
						{
							modelinepoints = 2;
							linepoints[i].digree = -0;
						}
					}
				}
			}
			else if (modelinepoints == 2)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (linepoints[i].mode == 1)
					{
						if (linepoints[i].digree > 270)
						{
							modelinepoints = 3;
							linepoints[i].digree = 270;
						}
					}
					else if (linepoints[i].mode == 0)
					{
						if (linepoints[i].digree < -270)
						{
							modelinepoints = 3;
							linepoints[i].digree = -270;
						}
					}
				}
			}
			else if (modelinepoints == 3)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (linepoints[i].lineLength < 10)
					{
						modelinepoints = 4;
						linepoints[i].lineLength = 0;
					}
				}
			}
			else if (modelinepoints == 4)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (linepoints[i].lineLength > 1000)
					{
						modelinepoints = 5;
						linepoints[i].digree = 0;
					}
				}
			}
			else if (modelinepoints == 5)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{


					if (linepoints[i].mode == 1)
					{
						if (linepoints[i].digree > 360)
						{
							modelinepoints = 6;
							linepoints[i].digree = 0;
						}
					}
					else if (linepoints[i].mode == 0)
					{
						if (linepoints[i].digree < -360)
						{
							modelinepoints = 6;
							linepoints[i].digree = 0;
						}
					}

				}

			}
			else if (modelinepoints == 6)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					
					if (linepoints[i].mode == 1)
					{
						if (linepoints[i].digree > 90)
						{
							modelinepoints = 7;
							linepoints[i].digree = 0;
						}
					}
					else if (linepoints[i].mode == 0)
					{
						if (linepoints[i].digree < -90)
						{
							modelinepoints = 7;
							linepoints[i].digree = 0;
						}
					}
						//cout << linepoints[i].digree << endl;
					
				}

			}
			else if (modelinepoints == 7)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					if (mode1 == 39)
					{
						modelinepoints = 8;
					}
						
						
				}

			}
			
			/*else if (modelinepoints == 8)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					for (int i = 0; i < linepoints.size(); i++)
					{
						if (linepoints[i].mode == 1)
						{
							if (linepoints[i].digree > 270)
							{
								modelinepoints = 9;
								linepoints[i].digree = 270;
							}
						}
						else if (linepoints[i].mode == 0)
						{
							if (linepoints[i].digree < -270)
							{
								modelinepoints = 9;
								linepoints[i].digree = -270;
							}
						}
					}
				}

			}*/
			/*else if (modelinepoints == 8)
			{
				for (int i = 0; i < linepoints.size(); i++)
				{
					for (int i = 0; i < linepoints.size(); i++)
					{
						if (linepoints[i].digree > 265)
						{
							modelinepoints = 9;
							//cout << "a" << endl;
						}
					}
				}

			}
			*/
		}
	}
	else if (modelinepoints == 8)
	{
		if (mode1 == 40)
		{
			if (linepoints.size() > 5)
			{
				linepoints.clear();
				movingpoints.clear();
			}
		}
	}
}
void ofApp::brighttowneffect2(int mode1)
{
	if (mode1 == 39)
	{
		if (brighttowns.size() < 10)
		{
			for (int i = 0; i < w[2]; i += 6) {
				for (int j = 0; j < h[2]; j += 4) {
					//ピクセルのRGBの値を取得
					int valueR = pixels[2][j * 3 * w[2] + i * 3];
					int valueG = pixels[2][j * 3 * w[2] + i * 3 + 1];
					int valueB = pixels[2][j * 3 * w[2] + i * 3 + 2];
					if (valueB < 50)
					{
						double kakudai = 2;
						double movedirect = atan(((double)j*ofGetHeight() / h[2] - ofGetHeight() / 2) / ((double)i*ofGetWidth() / w[2] - ofGetWidth() / 2));
						if ((double)i*ofGetWidth() / w[2] - ofGetWidth() / 2 < 0)
						{
							movedirect += M_PI;
						}
						Particle mybrighttown;

						mybrighttown.setup((double)i*kakudai + (ofGetWidth() / 2 - w[2] / 2 * kakudai), (double)j*kakudai + (ofGetHeight() / 2 - h[2] / 2 * kakudai),ofRandom(100, 400) * cos(movedirect) , ofRandom(100, 400) * sin(movedirect ), 255, 0, 0, 40);

						mybrighttown.time = brighttowntime+ofRandom(0,1000);
						brighttowns.push_back(mybrighttown);
					}
				}
			}
		}

	}
	else if(mode1==40)
	{
		for (int i = 0; i < brighttowns.size(); i++)
		{
			brighttowns[i].color[0] = ofRandom(0, 200);
			brighttowns[i].color[1] = ofRandom(0, 200);
			brighttowns[i].color[2] = ofRandom(0, 200);
			brighttowns[i].color[3] = soundvol * 60;

			brighttowns[i].update3(musictime);
		}
		for (int i = 0; i < brighttowns.size(); i++)
		{
			brighttowns[i].draw(8);
		}

	}
}
void ofApp::mousePressed(int x, int y, int button) {
	
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == ' ')
	{
		if (loadmusic == false)
		{
			ofHideCursor();
			
			//sound.setLoop(true);

			sound.play();
			sound.setVolume(0.1f);
			loadmusic = true;
			//sound.setPositionMS(200000);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {


}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
Particle::Particle() {
	friction = 0.01;
	mass = 1.0;
	bFixed = false;
}


void Particle::setup(float positionX, float positionY, float velocityX, float velocityY, int R, int G, int B, int A) {
	// 位置を設定
	position = ofVec3f(positionX, positionY,0);
	position1 = position;
	// 初期速度を設定
	velocity = ofVec3f(velocityX, velocityY,0);
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
}

// 力をリセット
void Particle::resetForce() {
	force.set(0, 0);
}

// 力を加える
void Particle::addForce(ofVec2f _force) {
	force += _force / mass;
}

// 摩擦力の更新
void Particle::updateForce() {
	force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos() {
	
		//velocity += force;
		position += velocity;
	
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle::update() {
	//updateForce();
	updatePos();
}
void Particle::update2() {
	velocity.x = (distination.x - position.x)/20;
	velocity.y = (distination.y - position.y) / 20;
	position += velocity;
}

void Particle::update3(int time1) {
	
	if (2000-(time1 - time) < 0)
	{
		position = position1;
	}
	else
	{
		position = position1+(ofPoint(ofGetWidth()/2, ofGetHeight() / 2,-1000)- position1)/2000 *(2000 - (double)(time1 - time));
	}
	color[3] *= (1000 + position.z) / 1500;
	//cout << (2000 - (double)(time1 - time)) <<endl;
}


// 画面の端でバウンドする(改定版)
void Particle::bounceOffWalls() {
	bool bDampedOnCollision = false;
	bool bDidICollide = false;

	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();

	if (position.x > maxx) {
		position.x = maxx;
		velocity.x *= -1;
		bDidICollide = true;
	}
	else if (position.x < minx) {
		position.x = minx;
		velocity.x *= -1;
		bDidICollide = true;
	}

	if (position.y > maxy) {
		position.y = maxy;
		velocity.y *= -1;
		bDidICollide = true;
	}
	else if (position.y < miny) {
		position.y = miny;
		velocity.y *= -1;
		bDidICollide = true;
	}

	if (bDidICollide == true && bDampedOnCollision == true) {
		velocity *= 0.3;
	}
}

void Particle::throughOfWalls() {
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	if (position.x < minx) {
		position.x = maxx;
	}
	if (position.y < miny) {
		position.y = maxy;
	}
	if (position.x > maxx) {                                                                                                                    
		position.x = minx;
	}
	if (position.y > maxy) {
		position.y = miny;
	}
}

// 描画
void Particle::draw(double radius) {
	ofFill();
	ofSetColor(color[0], color[1], color[2], color[3]);
	ofCircle(position, radius);
}

// 反発する力
void Particle::addRepulsionForce(float x, float y, float radius, float scale) {
	// 力の中心点を設定
	ofVec2f posOfForce;
	posOfForce.set(x, y);     
	// パーティクルと力の中心点との距離を計算
	ofVec2f diff = position - posOfForce;
	float length = diff.length();
	// 力が働く範囲かどうか判定する変数
	bool bAmCloseEnough = true;
	// もし設定した半径より外側だったら、計算しない
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	// 設定した半径の内側だったら
	if (bAmCloseEnough == true) {
		// 距離から点にかかる力ベクトルを計算
		float pct = 1 - (length / radius);
		diff.normalize();
		force.x = force.x + diff.x * scale * pct;
		force.y = force.y + diff.y * scale * pct;
	}
}

// 引き付けあう力
void Particle::addAttractionForce(float x, float y, float radius, float scale) {
	// 力の中心点を設定
	ofVec2f posOfForce;
	posOfForce.set(x, y);
	// パーティクルと力の中心点との距離を計算
	ofVec2f diff = position - posOfForce;
	float length = diff.length();
	// 力が働く範囲かどうか判定する変数
	bool bAmCloseEnough = true;
	// もし設定した半径より外側だったら、計算しない
	if (radius > 0) {
		if (length > radius) {
			bAmCloseEnough = false;
		}
	}
	// 設定した半径の内側だったら
	if (bAmCloseEnough == true) {
		// 距離から点にかかる力ベクトルを計算
		float pct = 1 - (length / radius);
		diff.normalize();
		
		
		force.x = force.x - diff.x * scale * pct;
		force.y = force.y - diff.y * scale * pct;
	}
}





Line::Line() {

}


void Line::setup(float positionX, float positionY, float velocityX, float velocityY, int R, int G, int B, int A, double width1,int timer, int lifetime,int mode1) {
	// 位置を設定
	position[0] = ofVec2f(positionX, positionY);
	position[1] = position[0];
	position[2] = position[0];
	// 初期速度を設定
	velocity = ofVec2f(velocityX, velocityY);
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	time = timer;
	life = lifetime;
	width = width1;
	mode = mode1;
	
	digree = atan(velocity.y / velocity.x);

	
}

// 力の更新と座標の更新をupdateとしてまとめる
void Line::update() {
	if (mode == 3)
	{
		if (ofGetElapsedTimeMillis() - time < life / 5 * 2)
		{
			position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
		}
		else
		{
			position[0].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time - life / 3));
			position[0].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time - life / 3));
		}
	}
	else if (mode == 4)
	{
		if (ofGetElapsedTimeMillis() - time >= life)
		{
			position[0].x = position[1].x;
			position[0].y = position[1].y;

		}
		else if (ofGetElapsedTimeMillis() - time < life / 7*3)
		{
			position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
		}
		else if (ofGetElapsedTimeMillis() - time > life / 7 * 4)
		{
			position[0].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time - life / 7* 4));
			position[0].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time - life / 7 * 4));
		}
	}

	else if (mode == 5)
	{
		position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
		position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
	}
	else if(mode == 6)
	{
		if (ofGetElapsedTimeMillis() - time < life / 6 * 5)
		{
			position[1].x = position[2].x + (velocity.x*1.5*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*1.5*(ofGetElapsedTimeMillis() - time));
		}
	}
	else if (mode == 18)
	{
		
		if (ofGetElapsedTimeMillis() - time < life / 2)
		{
			position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
		}
		else if(ofGetElapsedTimeMillis()  >= life +time)
		{
			position[0] = position[1];
		}
		else
		{
			position[0].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time - life / 2))*0.9;
			position[0].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time - life / 2))*0.9;
		}
		length = sqrt((position[0].y - position[1].y)*(position[0].y - position[1].y) + (position[0].x - position[1].x)*(position[0].x - position[1].x));
		if (length < 10)
		{
			length = 0;
		}

		position[3].x = position[0].x + (length / sqrt(2))*cos(digree - M_PI / 4);
		position[3].y = position[0].y + (length / sqrt(2))*sin(digree - M_PI / 4);
		//cout << "1" << endl;
	}
	else if (mode == 19)
	{
		if (ofGetElapsedTimeMillis() - time < life / 10*4)
		{
			position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
		}
		length = sqrt((position[0].y - position[1].y)*(position[0].y - position[1].y) + (position[0].x - position[1].x)*(position[0].x - position[1].x));
		if (length < 10)
		{
			length = 0;
		}

		position[3].x = position[0].x + (length / sqrt(2))*cos(digree - M_PI / 4);
		position[3].y = position[0].y + (length / sqrt(2))*sin(digree - M_PI / 4);
		if (ofGetElapsedTimeMillis() - time < life /10*4)
		{
			position[4] = position[3];
		}
		else if (ofGetElapsedTimeMillis() - time < life / 10 * 8)
		{
			centor = (position[1] - position[0]) / 2 + position[0];
			centorvec = position[3] - centor;
			position[4] =  centor + centorvec*cos((((double)ofGetElapsedTimeMillis() - time - life / 10*4) / (life / 10*4)) *  M_PI);
		}
		else
		{
			position[4] = centor - centorvec;
		}
		//cout << "1" << endl;
	}
	else if (mode == 20||mode==21)
	{
		if (ofGetElapsedTimeMillis() - time < life / 10 * 4)
		{
			position[1].x = position[2].x + (velocity.x*(ofGetElapsedTimeMillis() - time));
			position[1].y = position[2].y + (velocity.y*(ofGetElapsedTimeMillis() - time));
		}
		length = sqrt((position[0].y - position[1].y)*(position[0].y - position[1].y) + (position[0].x - position[1].x)*(position[0].x - position[1].x));
		if (length < 10)
		{
			length = 0;
		}

		position[3].x = position[0].x + (length / sqrt(2))*cos(digree - M_PI / 4);
		position[3].y = position[0].y + (length / sqrt(2))*sin(digree - M_PI / 4);
		if (ofGetElapsedTimeMillis() - time < life / 10 * 4)
		{
			position[4] = position[3];
		}
		else if (ofGetElapsedTimeMillis() - time < life / 10 * 8)
		{
			centor = (position[1] - position[0]) / 2 + position[0];
			centorvec = position[3] - centor;
			position[4] = centor + centorvec*cos((((double)ofGetElapsedTimeMillis() - time - life / 10 * 4) / (life / 10 * 4)) *  M_PI);
		}
		else
		{
			position[4] = centor - centorvec;
		}
		//cout << "1" << endl;
	}


}

// 描画
void Line::draw() {
	if ((mode == 4) && ofGetElapsedTimeMillis() - time > life / 5 * 4)
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], color[3]*50/(ofGetElapsedTimeMillis() - time - life / 5 * 4));
		ofDrawCircle(position[1], (ofGetElapsedTimeMillis() - time- life / 6 *5)*2);
	}

	else if (mode == 18)
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], color[3]);
		
		if (color[3] % 3 ==0)
		{
			ofDrawTriangle(position[0], position[3], position[1]);
		}
		else
		{
			ofDrawCircle(position[3], width / 2);
			ofDrawCircle(position[0], width / 2);
			ofDrawCircle(position[1], width / 2);
			ofNoFill();
			ofSetLineWidth(width);
			ofDrawTriangle(position[0], position[3], position[1]);
		}
	}
	else if (mode == 19)
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], color[3]);


		//ofDrawCircle(position[3], width / 2);
		//ofDrawCircle(position[0], width / 2);
		//ofDrawCircle(position[1], width / 2);
		//ofNoFill();
		ofSetLineWidth(width);
		ofDrawTriangle(position[0], position[3], position[1]);
		ofDrawTriangle(position[0], position[4], position[1]);
	}
	else if (mode == 20||mode==21)
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], color[3]);
		//ofDrawCircle(position[3], width / 2);
		//ofDrawCircle(position[0], width / 2);
		//ofDrawCircle(position[1], width / 2);
		//ofNoFill();
		ofSetLineWidth(width);
		ofDrawTriangle(position[0], position[3], position[1]);
		ofDrawTriangle(position[0], position[4], position[1]);
	}
	else
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], color[3]);
		ofDrawCircle(position[0], width/2);
		ofDrawCircle(position[1], width/2);
		ofSetLineWidth(width);
		ofDrawLine(position[0], position[1]);
	}
}


movingLine::movingLine() {

}


void movingLine::setup(ofVec2f position0, ofVec2f position1, double velocity0, double velocity1, int R, int G, int B, int A, double width1,int time1,int mode1) {
	// 位置を設定
	position[0] = position0;
	position[1] = position1;
	position[2].x = (double)(position[0].x - position[1].x)/2+ position1.x;
	position[2].y = (double)(position[0].y - position[1].y) / 2 + position1.y;
	position[3] = position[2];
	// 初期速度を設定
	velocity = velocity0;
	tvelocity = velocity1;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	mode = mode1;

	if (mode1 == 2||mode1==8||mode1==27)
	{
		digree = atan((double)(position[1].y - position[0].y) / (double)(position[1].x - position[0].x));
		if (position[1].x - position[0].x < 0)
		{
			digree += M_PI;
		}
	}
	else
	{
		digree = atan((double)(position[1].y - position[0].y) / (double)(position[1].x - position[0].x));
		if (position[1].x - position[0].x < 0)
		{
			digree += M_PI;
		}
		movedirect = atan((double)(position[2].y - ofGetHeight() / 2) / (position[2].x - ofGetWidth() / 2));
		if ((position[2].x - ofGetWidth() / 2)  < 0)
		{
			movedirect += M_PI;
		}
	}
	width = width1;
	length = sqrt((position[0].x - position[1].x)*(position[0].x - position[1].x) + (position[0].y - position[1].y)*(position[0].y - position[1].y));
	time = time1;
}


void movingLine::update() {
	if (mode == 2)
	{
		position[2].x = position[2].x + velocity*cos(digree - M_PI / 4 * 4)*(double)(ofGetElapsedTimeMillis() - time);
		position[2].y = position[2].y + velocity*sin(digree - M_PI / 4 * 4)*(double)(ofGetElapsedTimeMillis() - time);
		position[0].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[0].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[1].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
		position[1].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
	}
	else if(mode==4)
	{
		position[2].x = position[2].x + 0.02 * cos(movedirect) *(double)(ofGetElapsedTimeMillis() - time);
		position[2].y = position[2].y + 0.02* sin(movedirect) *(double)(ofGetElapsedTimeMillis() - time);
		position[0].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[0].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[1].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
		position[1].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
	}
	else if (mode == 27)
	{
		position[2].x = position[2].x + velocity*cos(digree )*(double)(ofGetElapsedTimeMillis() - time);
		position[2].y = position[2].y + velocity*sin(digree )*(double)(ofGetElapsedTimeMillis() - time);
		position[0].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[0].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time));
		position[1].x = position[2].x + length / 2 * cos(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
		position[1].y = position[2].y + length / 2 * sin(digree + tvelocity*(ofGetElapsedTimeMillis() - time) + M_PI);
	}
}

void movingLine::update2(int time2) {
	if (time2 >(ofGetElapsedTimeMillis() - time))
	{
		position[2].x = position[3].x + velocity*cos(digree - M_PI / 4 * 4+ tvelocity)*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[2].y = position[3].y + velocity*sin(digree - M_PI / 4 * 4+ tvelocity)*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[0].x = position[2].x + length / 2 * cos(digree +tvelocity/20*(time2 - (ofGetElapsedTimeMillis() - time)));
		position[0].y = position[2].y + length / 2 * sin(digree +tvelocity/20*(time2 - (ofGetElapsedTimeMillis() - time)));
		position[1].x = position[2].x + length / 2 * cos(digree + tvelocity/20*(time2 - (ofGetElapsedTimeMillis() - time)) + M_PI);
		position[1].y = position[2].y + length / 2 * sin(digree + tvelocity/20*(time2 - (ofGetElapsedTimeMillis() - time)) + M_PI);
		
	}
	else
	{
		color[0] = 255, color[1] = 255, color[2] = 255, color[3] = 255;
		position[2].x = position[3].x + velocity*cos(digree - M_PI / 4 * 4)*(double)(time2 - (ofGetElapsedTimeMillis() - time))*0;
		position[2].y = position[3].y + velocity*sin(digree - M_PI / 4 * 4)*(double)(time2 - (ofGetElapsedTimeMillis() - time))*0;
		position[0].x = position[2].x + length / 2 * cos(digree + 0 * tvelocity*(time2 - (ofGetElapsedTimeMillis() - time)));
		position[0].y = position[2].y + length / 2 * sin(digree + 0 * tvelocity*(time2 - (ofGetElapsedTimeMillis() - time)));
		position[1].x = position[2].x + length / 2 * cos(digree + 0 * tvelocity*(time2 - (ofGetElapsedTimeMillis() - time)) + M_PI);
		position[1].y = position[2].y + length / 2 * sin(digree + 0 * tvelocity*(time2 - (ofGetElapsedTimeMillis() - time)) + M_PI);
	}
}

// 描画
void movingLine::draw(int mode) {

	if (mode == 27)
	{
		ofSetLineWidth(width);
		ofSetColor(color[0], color[1], color[2], color[3] * 2);
		ofDrawLine(position[0], position[1]);
		//cout << position[2].x << endl;
	}
	else if (mode >= 7)
	{
		ofFill();
		ofSetColor(color[0], color[1], color[2], 255);
		//ofDrawCircle(position[0], width / 2);
		//ofDrawCircle(position[1], width / 2);
		ofSetLineWidth(width);
		ofSetColor(color[0], color[1], color[2], color[3] * 2);
		ofDrawLine(position[0], position[1]);
	}

	else
	{

		ofFill();
		ofSetColor(color[0], color[1], color[2], 255);
		ofDrawCircle(position[0], width / 2);
		ofDrawCircle(position[1], width / 2);
		ofSetLineWidth(width);
		ofSetColor(color[0], color[1], color[2], color[3] * 2);
		ofDrawLine(position[0], position[1]);
	}

}


movingTriangle::movingTriangle() {

}


void movingTriangle::setup(ofVec2f position0, ofVec2f position1, ofVec2f position2, double velocity0, double velocity1, int R, int G, int B, int A, double width1, int time1, int mode1) {
	// 位置を設定
	position[0] = position0;
	position[1] = position1;
	position[2]= position2;
	position[3] = (position1-position0)/2+position0;//centor
	position[4] = position0;
	position[5] = position1;
	position[6] = position2;
	mode = mode1;
	if (mode == 24)
	{
		
		double distinationR = 600;
		double distinationT = velocity1*1.2;
		distination.x =ofGetWidth()/2+ distinationR * cos(distinationT / 360 * 2 * M_PI);
		distination.y = ofGetHeight() / 2+ distinationR * sin(distinationT / 360 * 2 * M_PI);
		center.x = ofGetWidth()/2;
		center.y = ofGetHeight()/2;
		centorR = 100;
	
		
	}
	// 初期速度を設定
	
	tvelocity = velocity1;
	if (mode == 20)
	{
		velocity = position[2] - position[3];
	}
	else if (mode == 21)
	{
		velocity = position[2] - position[3];
	}
	else if (mode == 23)
	{
		double d = ofRandom(0, 360);
		time2 = ofRandom(2000,3500);
		double l = ofRandom(time2-300, time2) / 600;
		velocity.x = l*cos(2 * M_PI*d / 360);
		velocity.y = l*sin(2 * M_PI*d / 360);
	}
	else if (mode == 25)
	{
		double d = ofRandom(0, 360);
		double l = ofRandom(20, 120)*3 ;
		center.x = ofGetWidth() / 2;
		center.y = ofGetHeight() / 2;
		centorR = 100;

		velocity.x = l*cos(2 * M_PI*d / 360);
		velocity.y = l*sin(2 * M_PI*d / 360);
		tvelocity = ofRandom(1, 6) / 60;
	}
	else if (mode == 29)
	{
		double d = ofRandom(0, 360);
		double l = ofRandom(10, 60) * 2;
		center.x = ofGetWidth() / 2;
		center.y = ofGetHeight() / 2;
		centorR = 60;

		velocity.x = l*cos(2 * M_PI*d / 360);
		velocity.y = l*sin(2 * M_PI*d / 360);
		tvelocity = ofRandom(1, 6) / 60;
	}

	
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	
	
	
	width = width1;
	
	time = time1;
	
}


void movingTriangle::update(int mode1) {
	
	if (mode1 == 22)
	{
		if (mode == 21)
		{
			position[2].x = position[2].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
			position[2].y = position[2].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
			position[0].x = position[0].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
			position[0].y = position[0].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
			position[1].x = position[1].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
			position[1].y = position[1].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
		}
	}
	else if (mode1 == 24 ||mode1==25 || mode1==26 || mode1 == 27 || mode1 == 28||mode1 == 29 || mode1 == 30||mode1==31||mode1 == 32)
	{
		if (mode == 24)
		{
			center.x = (distination.x - center.x)*0.07 + (ofRandom(0, 80) - 40) / 20 + center.x;
			center.y = (distination.y - center.y)*0.07 + (ofRandom(0, 80) - 40) / 20 + center.y;
			position[0].x = center.x + centorR*cos(0 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
			position[0].y = center.y + centorR*sin(0 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
			position[1].x = center.x + centorR*cos(2 * M_PI / 3 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
			position[1].y = center.y + centorR*sin(2 * M_PI / 3 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
			position[2].x = center.x + centorR*cos(-2 * M_PI / 3 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
			position[2].y = center.y + centorR*sin(-2 * M_PI / 3 + 0.002*(double)(ofGetElapsedTimeMillis() - time) + tvelocity*0.075);
		}
		else if (mode == 25||mode == 29)//|| mode1 == 26 || mode1 == 27 || mode1 == 28)
		{
			center.x = center.x+velocity.x;
			center.y = center.y + velocity.y;
			position[0].x = center.x + centorR*cos(0 + tvelocity*(double)(ofGetElapsedTimeMillis() - time));
			position[0].y = center.y + centorR*sin(0 + tvelocity*(double)(ofGetElapsedTimeMillis() - time));
			position[1].x = center.x + centorR*cos(2 * M_PI / 3 + tvelocity*(double)(ofGetElapsedTimeMillis() - time) );
			position[1].y = center.y + centorR*sin(2 * M_PI / 3 + tvelocity*(double)(ofGetElapsedTimeMillis() - time) );
			position[2].x = center.x + centorR*cos(-2 * M_PI / 3 + tvelocity*(double)(ofGetElapsedTimeMillis() - time));
			position[2].y = center.y + centorR*sin(-2 * M_PI / 3 + tvelocity*(double)(ofGetElapsedTimeMillis() - time));
		}
	}
	
	else if (mode != 21)
	{
		position[2].x = position[2].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
		position[2].y = position[2].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
		position[0].x = position[0].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
		position[0].y = position[0].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
		position[1].x = position[1].x + velocity.x / 800 * (double)(ofGetElapsedTimeMillis() - time);
		position[1].y = position[1].y + velocity.y / 800 * (double)(ofGetElapsedTimeMillis() - time);
	}
	

}

void movingTriangle::update2(){
	if (time2 >(ofGetElapsedTimeMillis() - time))
	{
		position[0].x = position[4].x + velocity.x*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[0].y = position[4].y + velocity.y*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[1].x = position[5].x + velocity.x*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[1].y = position[5].y + velocity.y*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[2].x = position[6].x + velocity.x*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		position[2].y = position[6].y + velocity.y*(double)(time2 - (ofGetElapsedTimeMillis() - time));
		
	}
	else
	{
		position[0].x = position[4].x ;
		position[0].y = position[4].y ;
		position[1].x = position[5].x ;
		position[1].y = position[5].y ;
		position[2].x = position[6].x ;
		position[2].y = position[6].y ;
	}
	//cout << (int)ofGetElapsedTimeMillis() - time << "  "<< time<<endl;
}

// 描画
void movingTriangle::draw(int mode) {
	ofFill();
	ofSetColor(color[0], color[1], color[2], color[3]);
	ofDrawTriangle(position[0], position[1], position[2]);
	
}

movingTriangle2::movingTriangle2() {

}


void movingTriangle2::setup(ofVec2f center1, ofVec2f velocity0, double tvelocity0, int R, int G, int B, int A, double width, int time1, int lifetime){
	// 位置を設定
	center = center1;
	// 初期速度を設定
	velocity = velocity0;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	time = time1;
	life = lifetime;
	tvelocity = tvelocity0;
}

// 力をリセット


// 力の更新と座標の更新をupdateとしてまとめる
void movingTriangle2::update() {
	int r = 100;
	center += velocity;
	position[0].x = center.x + r*cos(tvelocity*(ofGetElapsedTimeMicros() - time));
	position[0].y = center.y + r*sin(tvelocity*(ofGetElapsedTimeMicros() - time));
	position[1].x = center.x + r*cos(2 * M_PI / 3 + tvelocity*(ofGetElapsedTimeMicros() - time));
	position[1].y = center.y + r*sin(2 * M_PI / 3 + tvelocity*(ofGetElapsedTimeMicros() - time));
	position[2].x = center.x + r*cos(-2 * M_PI / 3 + tvelocity*(ofGetElapsedTimeMicros() - time));
	position[2].y = center.y + r*sin(-2 * M_PI / 3 + tvelocity*(ofGetElapsedTimeMicros() - time));
}



// 描画
void movingTriangle2::draw() {
	ofFill();
	ofSetColor(color[0], color[1], color[2], color[3]);
	ofDrawTriangle(position[0], position[1], position[2]);
}


Particle3d::Particle3d() {

}


void Particle3d::setup(ofPoint positionD, ofVec3f velocityD, int R, int G, int B, int A, int timeD) {
	// 位置を設定
	position = positionD;
	position1 = positionD;
	// 初期速度を設定
	velocity = velocityD;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	time = timeD;
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle3d::update() {

	position = position1 + (ofGetElapsedTimeMillis() - time)*velocity;
	
	
	color[3] = (position1.z - position.z) / (position1.z*2) * 255;
	if (color[3] < 0)
	{
		color[3] = 255;
	}
	//cout << color[3] << endl;
}
void Particle3d::update2(double L) {

	position = position + velocity*L;


	color[3] = (position1.z - position.z) / (position1.z * 2) * 255;
	if (color[3] < 0)
	{
		color[3] = 255;
	}
	//cout << color[3] << endl;
}
// 描画
void Particle3d::draw(double radius) {
	ofFill();
	ofSetColor(color[0], color[1], color[2], color[3]);
	ofSetLineWidth(10);
	ofDrawLine(position, position+velocity*300);
}


controlbox::controlbox() {

}
void controlbox::setup(double Height1 ,double velocity1, double velocity2, int r, int R, int G, int B, int A, int timeD) {
	// 位置を設定
	// 初期速度を設定
	velocity = velocity1;
	velocityY = velocity2;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	time = timeD;
	double Height = Height1;
	
	Radius = r;
	position1 = ofPoint((ofGetWidth() / 2 ), ofGetHeight() / 2+Height, 1000);
}
// 力の更新と座標の更新をupdateとしてまとめる
void controlbox::update(int mode) {

	digree = velocity*(ofGetElapsedTimeMillis() - time)+M_PI/2;
	position = position1 + ofPoint(Radius*cos(digree),0, Radius*sin(digree));
	/*if (mode == 35)
	{
		position.y = position1.y + velocityY*(ofGetElapsedTimeMillis() - time)/50;
	}*/

	color[3] = 255/(1.5*Radius)*(Radius-(-position.z+750)) ;
	if (color[3] >255)
	{
		color[3] = 255;
	}
	//cout << color[3] << endl;
}

// 描画
void controlbox::draw() {

	ofSetColor(color[0], color[1], color[2], color[3]);
	ofSetLineWidth(5);
}


controlcylinder::controlcylinder() {

}
void controlcylinder::setup(double velocity1, int R, int G, int B, int A, int timeD) {
	// 位置を設定
	// 初期速度を設定
	velocity = velocity1;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	time = timeD;
	

	position1 = ofPoint((ofGetWidth() / 2), -10000,0);
}
// 力の更新と座標の更新をupdateとしてまとめる
void controlcylinder::update() {

	
	position = position1 + ofPoint(0, velocity*(ofGetElapsedTimeMillis() - time),0);

}

// 描画
void controlcylinder::draw() {

	ofSetColor(color[0], color[1], color[2], color[3]);
	ofSetLineWidth(5);
}


rollTriangle::rollTriangle() {

}

void rollTriangle::setup(ofPoint center1, ofPoint distination1,int timeD) {
	// 位置を設定
	center = center1;
	// 初期速度を設定
	distination = distination1;
	time = timeD;
}


// 力の更新と座標の更新をupdateとしてまとめる
void rollTriangle::update() {
	velocity.x = (distination.x - center.x) / 22;
	velocity.y = (distination.y -center.y) / 22;
	velocity.z= 0;
	center += velocity;

	int r = 100;
	center += velocity;
	if (distination.x - ofGetWidth() / 2 > 0)
	{
		position[0].x = center.x + r*cos(0+M_PI);
		position[0].y = center.y + r*sin(0 + M_PI);
		position[1].x = center.x + r*cos(2 * M_PI / 3 + M_PI);
		position[1].y = center.y + r*sin(2 * M_PI / 3 + M_PI);
		position[2].x = center.x + r*cos(-2 * M_PI / 3 + M_PI);
		position[2].y = center.y + r*sin(-2 * M_PI / 3 + M_PI);
	}
	else
	{
		position[0].x = center.x + r*cos(0);
		position[0].y = center.y + r*sin(0);
		position[1].x = center.x + r*cos(2 * M_PI / 3);
		position[1].y = center.y + r*sin(2 * M_PI / 3);
		position[2].x = center.x + r*cos(-2 * M_PI / 3);
		position[2].y = center.y + r*sin(-2 * M_PI / 3);
	}
	for (int i = 0; i < 3; i++)
	{
		position[i + 3] = position[i];
	}
}
void rollTriangle::update2(int time1) {

	double r[3];
	dig1 = (M_PI-dig1)/8+dig1;
	if (dig1 > M_PI)
	{
		dig1 = M_PI;
	}
	for (int i = 0; i < 3; i++)
	{
		r[i] = abs(position[3+i].x - ofGetWidth() / 2);
		position[i].y = position[i + 3].y;
		if (position[3 + i].x - ofGetWidth() / 2 < 0)
		{
			position[i].x = ofGetWidth() / 2 + r[i] * cos(dig1);
			position[i].z =  r[i] * sin(dig1);
		}
		else
		{
			position[i].x = ofGetWidth() / 2 + r[i] * cos(dig1+M_PI);
			position[i].z =  r[i] * sin(dig1+M_PI);
		}
	}
	//cout << dig << endl;
}
void rollTriangle::update3(int time1) {

	double r[3];
	dig2 = (M_PI - dig2) / 8 + dig2;
	if (dig2 > M_PI)
	{
		dig2 = M_PI;
	}
	for (int i = 0; i < 3; i++)
	{
		r[i] = abs(position[3 + i].y - ofGetHeight() / 2);
		position[i].x = position[i + 3].x;
		if (position[3 + i].y - ofGetHeight() / 2 < 0)
		{
			position[i].y = ofGetHeight() / 2 + r[i] * cos(dig2);
			position[i].z = r[i] * sin(dig2);
		}
		else
		{
			position[i].y = ofGetHeight() / 2 + r[i] * cos(dig2 + M_PI);
			position[i].z = r[i] * sin(dig2 + M_PI);
		}
	}
	//cout << dig << endl;
}




// 描画
void rollTriangle::draw(int time1) {
	if (time1 - time < 1500)
	{

		ofFill();
		ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
		ofDrawTriangle(position[0], position[1], position[2]);

	}
	else if (time1 - 1500 - time < 1500)
	{
		
		if (dig1>M_PI)
		{
			ofNoFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
		}
		else if (dig1  <M_PI / 2)
		{
			ofFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
			
		}
		else
		{
			ofNoFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
		}
	}
	else if (time1 - 3000 - time < 1500)
	{
		
		if (dig2>M_PI)
		{
			ofFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
		}
		else if (dig2  <M_PI/2)
		{
			ofNoFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
			
		}
		else 
		{
			ofFill();
			ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
			ofDrawTriangle(position[0], position[1], position[2]);
		}
	}
	else if (time1 - 4500 - time < 2500)
	{

		ofFill();
		ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 120);
		ofDrawTriangle(position[0], position[1], position[2]);

	}
}

rollTriangle2::rollTriangle2() {

}

void rollTriangle2::setup(ofPoint rollpoint1, double L1, int R, int G, int B, int A, int mode1,int timeD) {
	L = L1;
	mode = mode1;
	position[0] = rollpoint1;
	// 位置を設定
	if (mode == 0)//手前側、x+方向,軸2点
	{
		position[0] = position[0];
		position[1] = ofPoint(position[0].x, position[0].y + L, position[0].z);
		position[2] = ofPoint(position[0] .x-L/2*sqrt(3), position[0] .y + L/2, position[0] .z);

	}
	else if (mode == 1)//手前側,x-方向、軸2点
	{
		position[0] = position[0] ;
		position[1] = ofPoint(position[0] .x, position[0] .y + L, position[0] .z);
		position[2] = ofPoint(position[0] .x + L / 2 * sqrt(3), position[0] .y + L / 2, position[0] .z);
	}
	else if (mode == 2)//奥側、x+方向,軸1点
	{
		position[0] = position[0] ;
		position[1] = ofPoint(position[0] .x - L / 2 * sqrt(3), position[0] .y - L / 2, position[0] .z);
		position[2] = ofPoint(position[0] .x - L / 2 * sqrt(3), position[0] .y + L / 2, position[0] .z);
	}
	else if (mode == 3)//奥側、x-方向,軸1点
	{
		position[0] = position[0] ;
		position[1] = ofPoint(position[0] .x + L / 2 * sqrt(3), position[0] .y - L / 2, position[0] .z);
		position[2] = ofPoint(position[0] .x + L / 2 * sqrt(3), position[0] .y + L / 2, position[0] .z);
	}
	else if (mode == 4)//手前側、x+方向,軸2点
	{
		position[0] = position[0];
		position[1] = ofPoint(position[0].x, position[0].y + L, position[0].z);
		position[2] = ofPoint(position[0].x - L / 2 * sqrt(3), position[0].y + L / 2, position[0].z);

	}
	else if (mode == 5)//手前側,x-方向、軸2点
	{
		position[0] = position[0];
		position[1] = ofPoint(position[0].x, position[0].y + L, position[0].z);
		position[2] = ofPoint(position[0].x + L / 2 * sqrt(3), position[0].y + L / 2, position[0].z);
	}
	// 初期速度を設定
	
	time = timeD;
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	digree = 0;
}


// 力の更新と座標の更新をupdateとしてまとめる
void rollTriangle2::update() {
	digree = digree+(M_PI - digree)/1.7;
	if (mode == 0)//手前側、x+方向,軸2点
	{
		
		position[2] = ofPoint(position[0] .x - L / 2 * sqrt(3)*cos(digree), position[0] .y + L / 2, position[0] .z+ L / 2 * sqrt(3)*sin(digree));

	}
	else if (mode == 1)//手前側,x-方向、軸2点
	{
		
		position[2] = ofPoint(position[0] .x  +L / 2 * sqrt(3)*cos(digree), position[0] .y + L / 2, position[0] .z + L / 2 * sqrt(3)*sin(digree));
	}
	else if (mode == 2)//奥側、x+方向,軸1点
	{
		
		position[1] = ofPoint(position[0] .x - L / 2 * sqrt(3)*cos(digree), position[0] .y - L / 2, position[0] .z- L / 2 * sqrt(3)*sin(digree));
		position[2] = ofPoint(position[0] .x - L / 2 * sqrt(3)*cos(digree), position[0] .y + L / 2, position[0] .z- L / 2 * sqrt(3)*sin(digree));
	}
	else if (mode == 3)//奥側、x-方向,軸1点
	{
		
		position[1] = ofPoint(position[0] .x + L / 2 * sqrt(3)*cos(digree), position[0] .y - L / 2, position[0] .z -L / 2 * sqrt(3)*sin(digree));
		position[2] = ofPoint(position[0] .x + L / 2 * sqrt(3)*cos(digree), position[0] .y + L / 2, position[0] .z- L / 2 * sqrt(3)*sin(digree));
	}
}



// 描画
void rollTriangle2::draw (){
	if (fadingSW == false)
	{
		fading = (255 - fading) / 40 + fading;
	}
	else
	{
		fading = fading - fading / 10;
	}
	if (fadingSW == false)
	{
		if (fading > 120)
		{
			fadingSW = true;
		}
	}
	ofNoFill();
	if (fade)
	{
		ofSetColor(color[0], color[1], color[2], fading);
	}
	else
	{
		ofSetColor(color[0], color[1], color[2], color[3]);
		
	}
	ofDrawTriangle(position[0], position[1], position[2]);
}




movingpoint::movingpoint() {

}
void movingpoint::setup(int R, int G, int B, int A, int modeD, int timeD) {
	// 位置を設定
	// 初期速度を設定
	
	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	mode = modeD;
	Radius = 1000;
	if (mode == 0)
	{
		position[0] = ofPoint((ofGetWidth() / 2), ofGetHeight() / 2+300, 1000);
	}
	else if (mode == 1)
	{
		position[0] = ofPoint((ofGetWidth() / 2), ofGetHeight() / 2 - 300, 1000);
	}
	time = timeD;
}
// 力の更新と座標の更新をupdateとしてまとめる
void movingpoint::update(int musictime) {

	//digree = 0.0025*(double)(musictime - time) ;
	position[1] = position[0] + ofPoint(Radius*cos(digree+M_PI), 0, Radius*sin(digree+M_PI));
	/*if (mode == 35)
	{
	position.y = position1.y + velocityY*(ofGetElapsedTimeMillis() - time)/50;
	}*/

	color[3] = 255 / (1.5*Radius)*(Radius - (-position[1].z + 750));
	if (color[3] >255)
	{
		color[3] = 255;
	}
	//cout << musictime <<"  "<<time<< endl;
}

// 描画
void movingpoint::draw() {

	ofSetColor(color[0], color[1], color[2], color[3]);
	ofSetLineWidth(5);
}

linepoint::linepoint() {

}
void linepoint::setup( ofPoint centerD, int R, int G, int B, int A, int modeD, int timeD){
	// 位置を設定
	// 初期速度を設定

	color[0] = R;
	color[1] = G;
	color[2] = B;
	color[3] = A;
	//ofPoint center = centerD;
	mode = modeD;
	Radius = 1000;
	if (modeD == 0)
	{
		center = ofPoint((ofGetWidth() / 2), ofGetHeight() / 2 + 200, 1000);
	}
	else if(modeD == 1)
	{
		center = ofPoint((ofGetWidth() / 2), ofGetHeight() / 2 - 200, 1000);
	}
	time = timeD;
}
void linepoint::renewpoint(ofPoint sphereD)
{
	dposition=position[0]- sphereD;
	dposition = dposition.getNormalized();
	position[0] = sphereD;
}
// 力の更新と座標の更新をupdateとしてまとめる
void linepoint::update(int mode1) {
	if (mode1 == 0)//中心方向に棒を伸ばす
	{
		targetLength = 1050;
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		lineLength = (targetLength - lineLength) / 20 + lineLength;
		position[1] = position[0] + vecCenter*lineLength;
		position[2] = position[0];
		//cout << center.x << endl;
	}
	else if (mode1 == 1)//180ドまわる回転速度方向
	{
		//targetLength = 600;
		if (mode == 1)
		{
			digree += 3;
		}
		else
		{
			digree -= 3;
		}

		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		vecCenter.rotate(digree, dposition);
		lineLength = 1000;
		position[1] = position[0] + vecCenter*lineLength;
		position[2] = position[0];
		//cout << center.x << endl;
	}
	else if (mode1 ==2 )//Z軸周り360ド回転
	{
		targetLength = 1000;
		if (mode == 1)
		{
			digree += 3;
		}
		else
		{
			digree -= 3;
		}
		
		
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		vecCenter.rotate(digree, vecCenter.getPerpendicular(dposition));
		lineLength = 1000;
		position[1] = position[0] -vecCenter*lineLength;
		position[2] = position[0];
		//cout << center.x << endl;
	}
	else if (mode1 == 3)//450度回転する
	{
		targetLength = 0;
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		vecCenter.rotate(digree, vecCenter.getPerpendicular(dposition));
		lineLength = (targetLength - lineLength) / 5 + lineLength;
		position[1] = position[0] + lineLength*dposition.rotate(digree, vecCenter);;
		position[2] = position[0];
		//cout << center.x << endl;
	}
	else if (mode1 == 4)//450度回転する
	{
		targetLength = 1050;
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		lineLength = (targetLength - lineLength) / 10 + lineLength;
		position[1] = position[0] + vecCenter*lineLength;
		position[2] = position[0];
		if (mode == 1)
		{
			position[3] = position[0] + lineLength*vecCenter.getPerpendicular(dposition);
		}
		else
		{
			position[3] = position[0] - lineLength*vecCenter.getPerpendicular(dposition);
		}
		//cout << center.x << endl;
	}
	else if (mode1 == 5)//450度回転する
	{
		targetLength = 600;
		lineLength = (targetLength - lineLength) / 15 + lineLength;
		if (mode == 1)
		{
			digree += 2.5;
		}
		else
		{
			digree -= 2.5;
		}
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化
		vecCenter.rotate(digree, dposition);
		position[1] = position[0] + vecCenter*lineLength;
		position[2] = position[0];
		if (mode == 1)
		{
			position[3] = position[0] + lineLength*vecCenter.getPerpendicular(dposition);
		}
		else
		{
			position[3] = position[0] - lineLength*vecCenter.getPerpendicular(dposition);
		}
		
		//cout << center.x << endl;
	}
	else if (mode1 == 6)//450度回転する
	{
		
		if (mode == 1)
		{
			digree += 2.5;
		}
		else
		{
			digree -= 2.5;
		}
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化

		position[2] = position[0];
		//position[1] = position[0] + vecCenter*lineLength;
		if (mode == 1)
		{
			position[3] = position[0] + lineLength*vecCenter.getPerpendicular(dposition);
			position[1] = position[0] + lineLength*vecCenter.rotate(digree, vecCenter.getPerpendicular(dposition));
		}
		else
		{
			position[3] = position[0] - lineLength*vecCenter.getPerpendicular(dposition);
			position[1] = position[0] + lineLength*vecCenter.rotate(digree, vecCenter.getPerpendicular(dposition));
		}
		//cout << center.x << endl;
	}
	else if (mode1 == 7)//450度回転する
	{
		
		if (mode == 1)
		{
			digree += 2.5;
			if (digree > 270)
			{
				digree = 270;
			}
		}
		else
		{
			digree += 2.5;
			if (digree > +270)
			{
				digree = 270;
			}
		}
		//digree = 0;
		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化

		position[2] = position[0];
		if (mode == 1)
		{
			vector1 = vecCenter.getPerpendicular(dposition);
			vector2 = dposition;
			position[3] = position[0] + lineLength* vector1.rotate(digree, vecCenter);
			position[1] = position[0] + lineLength*vector2.rotate(digree, vecCenter);
		}
		else
		{
			vector1 = vecCenter.getPerpendicular(dposition);
			vector2 = dposition;
			position[3] = position[0] - lineLength*vector1.rotate(digree, vecCenter);
			position[1] = position[0] - lineLength*vector2.rotate(digree, vecCenter);

		}
		//cout << center.x << endl;
	}
	

	else if (mode1 == 8)//450度回転する
	{
		movecount++;

		vecCenter = center - position[0];
		double L = sqrt((center.x - position[0].x)*(center.x - position[0].x) + (center.y - position[0].y)*(center.y - position[0].y) + (center.z - position[0].z)*(center.z - position[0].z));
		vecCenter /= L;//正規化

		position[2] = position[0];
		if (mode == 1)
		{
			vector1 = vecCenter.getPerpendicular(dposition);
			vector2 = dposition;
			position[3] = position[0] + lineLength* vector1.rotate(270, vecCenter);
			position[1] = position[0] + lineLength*vector2.rotate(270, vecCenter);
			vector3 = (position[1] - position[3])/8;
			for (int i = 1; i < 4; i++)
			{
				position[i] += movecount*vector3;
			}
		}
		else
		{
			vector1 = vecCenter.getPerpendicular(dposition);
			vector2 = dposition;
			position[3] = position[0] - lineLength*vector1.rotate(270, vecCenter);
			position[1] = position[0] - lineLength*vector2.rotate(270, vecCenter);
			vector3 = (position[1] - position[3])/8;
			for (int i = 1; i < 4; i++)
			{
				position[i] += movecount*vector3;
			}

		}

		//cout << center.x << endl;
	}

	/*color[3] = 255 / (Radius)*(Radius - (-position[1].z + 750));
	if (color[3] >255)
	{
		color[3] = 255;
	}*/
	//cout << musictime <<"  "<<time<< endl;
	color[3] = 255;
}

// 描画
void linepoint::draw() {

	ofSetColor(color[0], color[1], color[2], color[3]);
	ofSetLineWidth(5);
}