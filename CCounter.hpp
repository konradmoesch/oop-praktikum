/*!\file CCounter.hpp
 * \brief Das Headerfile für die Klasse CCounter (aus Aufgabe 5).
 *
 * Langbeschreibung des Files in (CCounter.hpp),muss über Leerzeile von der Kurzbeschreibung abgetrennt werden
 */
#ifndef CCOUNTER_HPP_
#define CCOUNTER_HPP_

/*!
 * \class CCounter
 * \brief Klasse CCounter (aus Aufgabe 5) als Basisklasse eines Zählers
 *
 * CCounter() ist der parameterlose Konstruktor
 * virtual ~CCounter() ist der Destruktor
 * virtual void count() inkrementiert den Zähler
 * int getValue() const gibt den aktuellen Zählerstand zurück
 * void setValue(int val) setzt den Zähler auf den gegebenen Wert
 * bool operator<(const CCounter& c2) const vergleicht, ob der aufrufende Zähler kleiner ist als der Zähler hinter dem Operator
 * bool operator>(const CCounter& c2) const vergleicht, ob der aufrufende Zähler größer ist als der Zähler hinter dem Operator
 *
 * int m_value ist die private Membervariable für den aktuellen Zählerstand.
 */
class CCounter {

private:
	int m_value; //!< Private Membervariable für den aktuellen Zählerstand.
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
	 * virtuelle Basisfunktion zum Inkrementieren des Zählers (Funktionalität wird mittels Overload in einer ?? Klasse bereitgestellt)
	 * \todo Begriffe (Basisklasse u Vererbung) nutzen!
	 */
	virtual void count();
	/*!
	 * Funktion zum Abfragen des aktuellen Zählerstandes.
	 * @return der aktuelle Zählerstand wird als integer-Wert zurückgegeben
	 */
	int getValue() const;
	/*!
	 * Funktion zum Setzen des Zählerstandes.
	 * @param val	der Zählerstand wird auf diesen Wert gesetzt
	 */
	void setValue(int val);
	/*!
	 * Operator< zum Vergleichen der Zählerstände zweier Zähler.
	 * Wenn der Zählerstand des aufrufenden Zählerobjektes (Zähler vor dem Operator) kleiner ist als der des zu vergleichenden Zählers, wird true zurückgegeben. Sonst wird false zurückgegeben.
	 * @param c2	zu vergleichendes Zählerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Zähler vor dem Operator einen kleineren Zählerstand als der Zähler hinter dem Operator hat.
	 */
	bool operator<(const CCounter &c2) const;
	/*!
	 * Operator> zum Vergleichen der Zählerstände zweier Zähler.
	 * Wenn der Zählerstand des aufrufenden Zählerobjektes (Zähler vor dem Operator) größer ist als der des zu vergleichenden Zählers, wird true zurückgegeben. Sonst wird false zurückgegeben.
	 * @param c2	zu vergleichendes Zählerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Zähler vor dem Operator einen größeren Zählerstand als der Zähler hinter dem Operator hat.
	 */
	bool operator>(const CCounter &c2) const;

};

#endif /* CCOUNTER_HPP_ */
