

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
s_tm.Add( p );    // TaskManagerに登録     }  

for ( int i=0; i < 2; i++ ) { 
p = new PlayerTask(i);   
s_tm.Add( p );    // TaskManagerに登録     }    

// メインループの仮想イメージ   

for ( int frame=0; true; frame++ ) {     
// 10フレームに１回、Enemyを増やす  

if ( frame%10 == 0 ) {  
s_tm.Add( new EnemyTask() ); 
}    
s_tm.UpdateAll();        // 登録済みのタスクの全実行     
s_tm.RenderAll();        // 登録済みのタスクの全描画        
printf( "%dレーム目\n", frame );  

}}

class TaskManager {  
// リスト構造でのTaskを管理   
private Task    *m_pTop;   
// 登録済みのタスクを全部実行する処理   
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
printf( "僕が正義です\n" ); 
}
};

// タスクの削除ー＞自殺するケースが多い 
class EnemyTask : public Task{       
void    Update()   
{       

if ( m_life <= 0 ) {           
Kill();        // 自殺         
return;        }      
printf( "僕は悪い子です\n" );   
}
};-------------------------------------------
extern TaskManager    s_tm;
class Task
{    // 自殺する場合     public void    Kill()   
{      
TaskManager.GetInstance()->Kill( this );    // Taskマネージャーから削除してもらう 
}   
// 外部から殺してもらう場合   
static public void    Kill( Task *p )  
{      
TaskManager.GetInstance()->Kill( p );    // Taskマネージャーから削除してもらう
}
};--------------------------------------------
// シングルトン ・1個しか存在しないもの・アクセスするためのメソッドが用意されている
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

