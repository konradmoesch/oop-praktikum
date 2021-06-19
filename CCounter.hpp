/*!\file CCounter.hpp
 * \brief Das Headerfile f�r die Klasse CCounter (aus Aufgabe 5).
 *
 * Langbeschreibung des Files in (CCounter.hpp),muss �ber Leerzeile von der Kurzbeschreibung abgetrennt werden
 */
#ifndef CCOUNTER_HPP_
#define CCOUNTER_HPP_

/*!
 * \class CCounter
 * \brief Klasse CCounter (aus Aufgabe 5) als Basisklasse eines Z�hlers
 *
 * CCounter() ist der parameterlose Konstruktor
 * virtual ~CCounter() ist der Destruktor
 * virtual void count() inkrementiert den Z�hler
 * int getValue() const gibt den aktuellen Z�hlerstand zur�ck
 * void setValue(int val) setzt den Z�hler auf den gegebenen Wert
 * bool operator<(const CCounter& c2) const vergleicht, ob der aufrufende Z�hler kleiner ist als der Z�hler hinter dem Operator
 * bool operator>(const CCounter& c2) const vergleicht, ob der aufrufende Z�hler gr��er ist als der Z�hler hinter dem Operator
 *
 * int m_value ist die private Membervariable f�r den aktuellen Z�hlerstand.
 */
class CCounter {

private:
	int m_value; //!< Private Membervariable f�r den aktuellen Z�hlerstand.
public:
	/*!
	 * parameterloser Konstruktor
	 */
	CCounter();
	/*!
	 * Destruktor (virtual, da CCounter eine Basisklasse ist)
	 */
	virtual ~CCounter();
	/*!
	 * virtuelle Basisfunktion zum Inkrementieren des Z�hlers (Funktionalit�t wird mittels Overload in einer ?? Klasse bereitgestellt)
	 * \todo Begriffe (Basisklasse u Vererbung) nutzen!
	 */
	virtual void count();
	/*!
	 * Funktion zum Abfragen des aktuellen Z�hlerstandes.
	 * @return der aktuelle Z�hlerstand wird als integer-Wert zur�ckgegeben
	 */
	int getValue() const;
	/*!
	 * Funktion zum Setzen des Z�hlerstandes.
	 * @param val	der Z�hlerstand wird auf diesen Wert gesetzt
	 */
	void setValue(int val);
	/*!
	 * Operator< zum Vergleichen der Z�hlerst�nde zweier Z�hler.
	 * Wenn der Z�hlerstand des aufrufenden Z�hlerobjektes (Z�hler vor dem Operator) kleiner ist als der des zu vergleichenden Z�hlers, wird true zur�ckgegeben. Sonst wird false zur�ckgegeben.
	 * @param c2	zu vergleichendes Z�hlerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Z�hler vor dem Operator einen kleineren Z�hlerstand als der Z�hler hinter dem Operator hat.
	 */
	bool operator<(const CCounter &c2) const;
	/*!
	 * Operator> zum Vergleichen der Z�hlerst�nde zweier Z�hler.
	 * Wenn der Z�hlerstand des aufrufenden Z�hlerobjektes (Z�hler vor dem Operator) gr��er ist als der des zu vergleichenden Z�hlers, wird true zur�ckgegeben. Sonst wird false zur�ckgegeben.
	 * @param c2	zu vergleichendes Z�hlerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Z�hler vor dem Operator einen gr��eren Z�hlerstand als der Z�hler hinter dem Operator hat.
	 */
	bool operator>(const CCounter &c2) const;

};

#endif /* CCOUNTER_HPP_ */
