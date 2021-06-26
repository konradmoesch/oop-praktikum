/*!\file CCounter.hpp
 * \brief Das Headerfile fuer die Klasse CCounter (aus Aufgabe 5).
 *
 * Langbeschreibung des Files in (CCounter.hpp),muss ueber Leerzeile von der Kurzbeschreibung abgetrennt werden
 */
#ifndef CCOUNTER_HPP_
#define CCOUNTER_HPP_

/*!
 * \class CCounter
 * \brief Klasse CCounter (aus Aufgabe 5) als Basisklasse eines Zaehlers
 *
 * CCounter() ist der parameterlose Konstruktor
 * virtual ~CCounter() ist der Destruktor
 * virtual void count() inkrementiert den Zaehler
 * int getValue() const gibt den aktuellen Zaehlerstand zurueck
 * void setValue(int val) setzt den Zaehler auf den gegebenen Wert
 * bool operator<(const CCounter& c2) const vergleicht, ob der aufrufende Zaehler kleiner ist als der Zaehler hinter dem Operator
 * bool operator>(const CCounter& c2) const vergleicht, ob der aufrufende Zaehler groeﬂer ist als der Zaehler hinter dem Operator
 *
 * int m_value ist die private Membervariable fuer den aktuellen Zaehlerstand.
 */
class CCounter {

private:
	int m_value; //!< Private Membervariable fuer den aktuellen Zaehlerstand.
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
	 * virtuelle Basisfunktion zum Inkrementieren des Zaehlers (Funktionalitaet wird mittels Overload in einer ?? Klasse bereitgestellt)
	 */
	virtual void count();
	/*!
	 * Funktion zum Abfragen des aktuellen Zaehlerstandes.
	 * @return der aktuelle Zaehlerstand wird als integer-Wert zurueckgegeben
	 */
	int getValue() const;
	/*!
	 * Funktion zum Setzen des Zaehlerstandes.
	 * @param val	der Zaehlerstand wird auf diesen Wert gesetzt
	 */
	void setValue(int val);
	/*!
	 * Operator< zum Vergleichen der Zaehlerstaende zweier Zaehler.
	 * Wenn der Zaehlerstand des aufrufenden Zaehlerobjektes (Zaehler vor dem Operator) kleiner ist als der des zu vergleichenden Zaehlers, wird true zurueckgegeben. Sonst wird false zurueckgegeben.
	 * @param c2	zu vergleichendes Zaehlerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Zaehler vor dem Operator einen kleineren Zaehlerstand als der Zaehler hinter dem Operator hat.
	 */
	bool operator<(const CCounter &c2) const;
	/*!
	 * Operator> zum Vergleichen der Zaehlerstaende zweier Zaehler.
	 * Wenn der Zaehlerstand des aufrufenden Zaehlerobjektes (Zaehler vor dem Operator) groeﬂer ist als der des zu vergleichenden Zaehlers, wird true zurueckgegeben. Sonst wird false zurueckgegeben.
	 * @param c2	zu vergleichendes Zaehlerobjekt (steht direkt hinter dem Operator).
	 * @return  true, wenn der Zaehler vor dem Operator einen groeﬂeren Zaehlerstand als der Zaehler hinter dem Operator hat.
	 */
	bool operator>(const CCounter &c2) const;

};

#endif /* CCOUNTER_HPP_ */
