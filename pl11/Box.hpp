#ifndef BOX_HPP
#define BOX_HPP

class Box
{
public:
	Box();
	~Box();
	
	void setOcupado(bool i);
	bool getOcupado();

private:
	bool ocupado;

};

#endif // BOX_HPP
