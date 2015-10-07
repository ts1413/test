S2B-Qの対応モデルについて

・ QGen,Reactisが対応しているブロックに対応(予定)。
・ QGen,Reactisが対応しているブロックはnameの"QGen Support","Reactis Support"の項目を参照。
・ QGenについて以下の設定はエラーとなるので、注意。
	○ fixdt(1,16)型 (fixdt(1,16,0)などは扱うことが可能)
	○ Saturationブロック以外での値の上限、下限の指定 (「整数オーバーフローで飽和」なども)
・ 各ブロックのブロックパラメータの指定やその他備考についてはQGen Notes,Reactis Notesの項目を参照。