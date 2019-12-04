#ifndef SIT_H
#define SIT_H
#include "ASitovyPrvek.h"
struct Sit {
private:
	Fronta<ASitovyPrvek*> sitovePrvky;
	void ZpracujPrvky();
public:
	static int idZpravy;
	Sit();
	~Sit();
	int static DejNoveId() {
		return idZpravy++;
	}
	void Pripoj(ASitovyPrvek* sp);
	void ProvadejVse();
};

#endif // !SIT_H

