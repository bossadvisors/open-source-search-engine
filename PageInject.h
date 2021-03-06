#ifndef GBINJECT_H
#define GBINJECT_H    

void  handleRequest7 ( class UdpSlot *slot , long netnice ) ;

bool sendPageInject ( class TcpSocket *s, class HttpRequest *hr );

bool resumeImports ( ) ;

// called by Process.cpp
void saveImportStates ( ) ;

#include "XmlDoc.h"
#include "Users.h"
#include "Parms.h" // GigablastRequest

class Msg7 {

public:

	GigablastRequest m_gr;
	SafeBuf m_injectUrlBuf;
	bool m_firstTime;
	char *m_start;
	bool  m_fixMe;
	long  m_injectCount;

	bool       m_needsSet;
	XmlDoc     m_xd;
	TcpSocket *m_socket;
	SafeBuf    m_sb;
	char m_round;
	char m_useAhrefs;
	HashTableX m_linkDedupTable;

	SafeBuf m_sbuf; // for holding entire titlerec for importing

	void *m_state;
	void (* m_callback )(void *state);

	//long long m_hackFileOff;
	//long m_hackFileId;

	//long m_crawlbotAPI;

	class ImportState *m_importState;

	//void constructor();
	Msg7 ();
	~Msg7 ();
	bool m_inUse;

	void reset();

	bool scrapeQuery ( );

	bool inject ( char *coll,
		      char *proxiedUrl,
		      long  proxiedUrlLen,
		      char *content,
		      void *state ,
		      void (*callback)(void *state) );

	bool inject ( void *state ,
		      void (*callback)(void *state) );


	//bool injectTitleRec ( void *state ,
	//		      void (*callback)(void *state) ,
	//		      class CollectionRec *cr );

	void gotMsg7Reply ();

};

extern bool g_inPageInject;

#endif
