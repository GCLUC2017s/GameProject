

#include<stdio.h>
#include"CTask.h"
#include"CPlayer.h"


int main() {
	CTask l_task;

	for (int i; i < 5; i++) {
		l_task.Add(new CTask());
		l_task.Add (new CPlayerTask());
	}
	for (; true;) {
		l_task.Update();
	}

	getchar();
}

/*
TaskManager    s_tm;

void    main(){  
Task *p; 

for ( int i=0; i < 5; i++ ) {   

p = new EnemyTask();    
s_tm.Add( p );    // TaskManager�ɓo�^     }  

for ( int i=0; i < 2; i++ ) { 
p = new PlayerTask(i);   
s_tm.Add( p );    // TaskManager�ɓo�^     }    

// ���C�����[�v�̉��z�C���[�W   

for ( int frame=0; true; frame++ ) {     
// 10�t���[���ɂP��AEnemy�𑝂₷  

if ( frame%10 == 0 ) {  
s_tm.Add( new EnemyTask() ); 
}    
s_tm.UpdateAll();        // �o�^�ς݂̃^�X�N�̑S���s     
s_tm.RenderAll();        // �o�^�ς݂̃^�X�N�̑S�`��        
printf( "%d���[����\n", frame );  

}}

class TaskManager {  
// ���X�g�\���ł�Task���Ǘ�   
private Task    *m_pTop;   
// �o�^�ς݂̃^�X�N��S�����s���鏈��   
public void    UpdateAll()   
{       
Task    *p = m_pTop;   
for ( ; p != null; p=p->m_next ) { 
p->Update();        
}    }
};

class PlayerTask : public Task
{    
void Update()    
{     
printf( "�l�����`�ł�\n" ); 
}
};

// �^�X�N�̍폜�[�����E����P�[�X������ 
class EnemyTask : public Task{       
void    Update()   
{       

if ( m_life <= 0 ) {           
Kill();        // ���E         
return;        }      
printf( "�l�͈����q�ł�\n" );   
}
};-------------------------------------------
extern TaskManager    s_tm;
class Task
{    // ���E����ꍇ     public void    Kill()   
{      
TaskManager.GetInstance()->Kill( this );    // Task�}�l�[�W���[����폜���Ă��炤 
}   
// �O������E���Ă��炤�ꍇ   
static public void    Kill( Task *p )  
{      
TaskManager.GetInstance()->Kill( p );    // Task�}�l�[�W���[����폜���Ă��炤
}
};--------------------------------------------
// �V���O���g�� �E1�������݂��Ȃ����́E�A�N�Z�X���邽�߂̃��\�b�h���p�ӂ���Ă���
TaskManager.hppclass TaskManager
{
private:    static TaskManager    *ms_instance;  
public:    static TaskManager    *GetInstance();
};--------------
TaskManager.cppTaskManager 
*TaskManager::ms_instance = null;TaskManager  
*TaskManager::GetInstance()
{    
if ( ms_instance == null ) {     
ms_instance = new TaskManager();   
}    
return ms_instance;
}

*/

