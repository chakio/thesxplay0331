#pragma once

#include "ofMain.h"





class Particle {
public:

	
	ofVec2f frc; //��(�����x)
	int color[4];//���q�̐F
	float damping; //���C��

				   //�R���X�g���N�^
	Particle();
	// �����ݒ�
	void setup(float positionX, float positionY, float velocityX, float velocityY,int R,int G,int B, int A);
	// �͂����Z�b�g
	void resetForce();
	// �͂�������
	void addForce(ofVec2f force);
	// �͂��X�V
	void updateForce();
	// �ʒu�̍X�V
	void updatePos();
	// �X�V(�ʒu�Ɨ�)
	void update();
	void update2();
	void update3(int time1);
	// ��ʂ���͂ݏo����o�E���h������
	void bounceOffWalls();
	// ��ʂ���͂ݏo���甽�Α�����o��
	void throughOfWalls();
	// �`��
	void draw(double raduis);

	// ���������
	void addRepulsionForce(float x, float y, float radius, float scale);
	// ������������
	void addAttractionForce(float x, float y, float radius, float scale);

	// �ʒu�x�N�g���̔z��
	ofVec3f position;
	ofVec3f position1;//�����̏ꏊ
	ofVec2f distination;
	// ���x�x�N�g���̔z��
	ofVec3f velocity;
	// �̓x�N�g���̔z��
	ofVec2f force;
	// ���C�W��
	float friction;
	// �p�[�e�B�N���̔��a
	double  Radius;
	double  digree;
	// �Œ肷�邩�ǂ���
	bool bFixed;
	// �p�[�e�B�N���̎���
	float mass;

	int time;
	double M_PI = 3.14159265359;


};


class Line {
public:


	int color[4];//���̐F
	Line();
	// �����ݒ�
	void setup(float positionX, float positionY, float velocityX, float velocityY, int R, int G, int B, int A, double width,int time, int lifetime,int mode1);

	void update();
	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofVec2f position[5];
	ofVec2f centor;
	ofVec2f centorvec;

	// ���x�x�N�g���̔z��
	ofVec2f velocity;


	double time;
	double life;
	double width;
	double M_PI = 3.14159265359;
	int mode = 0;
	double digree;
	double length;
	bool fill;


};
class movingLine {
public:


	int color[4];//���̐F
	movingLine();
	// �����ݒ�
	void setup(ofVec2f position0, ofVec2f position1, double velocity0, double velocity1, int R, int G, int B, int A, double width,int time1,int mode1);

	void update();
	void update2(int time);
	// �`��
	void draw(int mode);

	// �ʒu�x�N�g���̔z��
	ofVec2f position[5];
	// ���x�x�N�g���̔z��
	double velocity;
	double tvelocity;

	double width;
	double digree;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;
	ofVboMesh mesh;

};
class movingTriangle {
public:


	int color[4];//���̐F
	movingTriangle();
	// �����ݒ�
	void setup(ofVec2f position0, ofVec2f position1, ofVec2f position2, double velocity0, double velocity1, int R, int G, int B, int A, double width, int time1, int mode1);

	void update(int mode);
	void update2();
	
	// �`��
	void draw(int mode);

	// �ʒu�x�N�g���̔z��
	ofVec2f position[7];
	// ���x�x�N�g���̔z��
	ofVec2f velocity;
	ofVec2f distination;
	ofVec2f center;
	double centorR;
	double tvelocity;

	double width;
	double digree;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;
	int mode24;

};
class movingTriangle2 {
public:


	int color[4];//���̐F
	movingTriangle2();
	// �����ݒ�
	void setup(ofVec2f center1, ofVec2f velocity0, double tvelocity0, int R, int G, int B, int A, double width, int time1, int life);

	void update();
	
	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofPoint position[3];
	// ���x�x�N�g���̔z��
	ofVec2f velocity;
	ofVec2f center;
	double centorR;
	double tvelocity;

	double width;
	double digree;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;
	int life;

};

class Particle3d {
public:


	ofVec2f frc; //��(�����x)
	int color[4];//���q�̐F
	float damping; //���C��

				   //�R���X�g���N�^
	Particle3d();
	// �����ݒ�
	void setup(ofPoint position, ofVec3f velocity, int R, int G, int B, int A, int time);
	// �͂����Z�b�g
	// �X�V(�ʒu�Ɨ�)
	void update();
	void update2(double L);

	// �`��
	void draw(double raduis);

	// �ʒu�x�N�g���̔z��
	ofVec3f position;
	ofVec3f position1;//�����̏ꏊ
					  //ofVec2f distination;
					  // ���x�x�N�g���̔z��
	ofVec3f velocity;


	// �p�[�e�B�N���̔��a
	double  Radius;
	double  digree;


	double M_PI = 3.14159265359;
	int time;

};
class  controlbox {
public:


	
	int color[4];//box�̐F
	

				   //�R���X�g���N�^
	controlbox();
	// �����ݒ�
	void setup(double Height1, double velocity1, double velocityY,int r, int R, int G, int B, int A, int timeD);
	// �͂����Z�b�g
	// �X�V(�ʒu�Ɨ�)
	void update(int mode);

	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofVec3f position;
	ofVec3f position1;//�����̏ꏊ
					  //ofVec2f distination;
					  // ���x�x�N�g���̔z��
	double velocity;
	double velocityY;


	// �p�[�e�B�N���̔��a
	double  Radius;
	double  digree;


	double M_PI = 3.14159265359;
	int time;
	int num;

};
class  controlcylinder {
public:



	int color[4];//box�̐F


				 //�R���X�g���N�^
	controlcylinder();
	// �����ݒ�
	void setup(double velocity1, int R, int G, int B, int A, int timeD);
	// �͂����Z�b�g
	// �X�V(�ʒu�Ɨ�)
	void update();

	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofVec3f position;
	ofVec3f position1;//�����̏ꏊ
					  //ofVec2f distination;
					  // ���x�x�N�g���̔z��
	double velocity;


	// �p�[�e�B�N���̔��a
	//double  Radius;
	//double  digree;


	double M_PI = 3.14159265359;
	int time;
	//int num;

};

class rollTriangle {
public:


	int color[4];//���̐F
	rollTriangle();
	// �����ݒ�
	void setup(ofPoint center1, ofPoint distination1,int time);

	void update();
	void update2(int musictime);
	void update3(int musictime);

	// �`��
	void draw(int musictime);

	// �ʒu�x�N�g���̔z��
	ofPoint position[6];
	ofPoint distination;
	ofPoint center;
	// ���x�x�N�g���̔z��
	ofVec3f velocity;
	
	double centorR;
	double tvelocity;

	double width;
	double digree, dig1 = 0 , dig2=0;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;

};

class rollTriangle2 {
public:


	int color[4];//���̐F
	rollTriangle2();
	// �����ݒ�
	void setup(ofPoint rollpoint1, double L, int R, int G, int B, int A, int mode,int time);

	void update();
	

	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofPoint position[6];
	ofPoint distination;
	double L;
	// ���x�x�N�g���̔z��
	ofVec3f velocity;

	double centorR;
	double tvelocity;

	double width;
	double digree, dig1 = 0, dig2 = 0;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;
	bool fade=false;
	double fading = 0;
	bool fadingSW = false;
};
class movingpoint {
public:


	int color[4];//���̐F
	movingpoint();
	// �����ݒ�
	void setup(int R, int G, int B, int A, int mode, int time);

	void update(int mode);


	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofPoint position[6];
	ofPoint distination;
	double L;
	// ���x�x�N�g���̔z��
	ofVec3f velocity;

	
	double Radius;
	
	double digree, digree1 = 0, dig1 = 0, dig2 = 0;
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;

};
class linepoint {
public:


	int color[4];//���̐F
	linepoint();
	// �����ݒ�
	void setup (ofPoint centerD,int R, int G, int B, int A, int mode, int time);
	void renewpoint(ofPoint sphere);
	void update(int mode);


	// �`��
	void draw();

	// �ʒu�x�N�g���̔z��
	ofPoint position[6];
	ofPoint center;
	double L;
	// ���x�x�N�g���̔z��
	ofVec3f velocity;
	ofVec3f vecCenter;//���S�����ւ̃x�N�g��
	ofVec3f dposition;
	ofVec3f vector1, vector2,vector3;
	double Radius;

	double digree = 0, digree1 = 0, dig1 = 0, dig2 = 0;
	//double digreeC;//���S�ɑ΂���p�x
	double length;
	int time;
	int time2;
	double M_PI = 3.14159265359;
	double movedirect;
	int mode;
	double lineLength = 0;
	double targetLength;
	double movecount=0;

};

class ofApp : public ofBaseApp{

	public:
		bool loadmusic = false;
		void setup();
		void update();
		void draw();

		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		void plot(float* buffer, float scale);
		void circles(int mode);
		// linesonpic(int mode);
		//void particlewrite();
		//void fftviewer();
		//void balllines(int mode);
		//void wiredball();
		//void lineseffect();
		//void wiredfft();
		//void movingpic();
		void lineeffectv2(int mode);
		void lineeffectv3(int mode);
		void triangleeffect(int mode);
		//void lineeffectv32(int mode);
		void brighttowneffect(int mode);
		void sxplayburst(int mode);
		void brightingpoint(int mode);
		void triangleeffectv2(int mode);
		void triangleburst(int mode);
		void triangleemitter(int mode);
		void infiniteburst(int mode);
		void throughsxplay(int mode);
		void commingparticle(int mode);
		void commingparticle2(int mode);
		void downcylinder(int mode);
		void rollingbox(int mode);
		void rollingtriangle(int mode);
		void bigtriangle(int mode);
		void pointeffect(int mode);
		void brighttowneffect2(int mode);
		ofSoundPlayer sound;
		
		float* fft;
		double soundvol = 0;
		double soundvolave;
		
		int s = 3;
		int sceen = 0;
		int pos = 0;
		int commingparticle2time;
		
		double center = 0;

		vector <Particle> particles;
	
		vector <ofVec2f> position;
		vector <Line>lines;
		vector <movingLine>movinglines;
		vector <Particle> brighttowns;
		vector <Particle>lineemitparticles;
		vector <movingLine> sxplayelement;
		vector <Particle> sxplayparticles;
		vector <Particle> brightpoints;
		vector <movingTriangle>movingTriangles;
		vector <movingTriangle>movingTriangles2;
		vector <movingTriangle>movingTriangles3;
		vector <movingTriangle>movingTriangles4;
		vector <movingTriangle2>emittingTriangles[2];
		vector <movingLine>movinglines2;
		vector <movingTriangle>burstTriangles;
		vector < Particle3d> particles3d;
		vector<ofBoxPrimitive> boxes;
		vector<controlbox>controlboxes;
		vector<ofCylinderPrimitive> cylinders;
		vector<controlcylinder>controlcylinders;
		vector<rollTriangle>rollTriangles;
		vector<rollTriangle2>rollTriangles2;
		vector<movingpoint>movingpoints;
		vector<ofSpherePrimitive> spheres;
		vector<linepoint>linepoints;

		const char* picnames[14];
		ofVec2f sxplaypoint[31];
		ofVec2f sxpointline[23];
		ofVec2f sxplaypoint2[31];
		double sxplayL[31], sxplayDig[31];
		// ���b�V��
		ofVboMesh mesh;
		// ���͂������Ă��邩
		bool atraction;
		// �p�[�e�B�N���̐�
		static const int NUM = 100;

		
		int picnum = 0;
		vector <double>picpoint[14][2]; //0:R 1:theta
		ofPath line;
		vector<ofPoint> Bezier;
		unsigned char * pixels[14];
		int w[14];
		int h[14];
		ofImage image[14];
		double time = 0;
		ofLight light; // ���C�g
		//ofSpherePrimitive sphere;
		double M_PI = 3.14159265359;

		int boxnum = 0;
		

		int musictime;
		int triangles=0;
		int lineeffectv2count = 0;
		bool lineeffectv2timing = true;
		bool movinglinesreset = 0;
		bool triangleeffecttiming = true;
		int triangleeffectcount = 0;

		ofTrueTypeFont text;
		ofPoint emitcenter[2],emitcenterold[2],emitvelocity[2];
		double emitvelocitydigree[2];
		int emittingtime1, emittingtime;
		int emittingtime3, emittingtime2;
		int liningtime1, liningtime;
		int sxplaytime ;
		int rollingtime = 0;
		bool cy = true;
		double triangleR = 100;
		bool rolltriangle = false;
		int rolltriangletime;
		bool rolltriangleend = false;
		double targetR;
		int brighttowntime;
		double infinitR=300;
		int triangleC = 0;
		int bigtriangletime;
		bool increasetriangle = false;
		int rollingcount = 0;
		int rollingmode = 0;
		bool rollingend = false;
		int modelinepoints = 0;
		double  bigtriangleR=100;
		double kosa = 50;
		double particlespeed;
		//void mousePressed(int x, int y, int button) {
			
};

