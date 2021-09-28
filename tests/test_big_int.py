import os
from settings import *

def test_dict_print():
  output_lines = [
"9999999999999",
"2",
"263644553644553",
"263644553644553000000",
"32132132132132134",
"231321321321323",
"1111111111111",
"-8888888888888",
"11111111111111",
"2222222222222222",
"2222222222222220",
"4294967296",
"340282366920938463463374607431768211456",
"70550791086553325712464271575934796216507949612787315762871223209262085551582934156579298529447134158154952334825355911866929793071824566694145084454535257027960285323760313192443283334088001",
"1747871251722651609659974619164660570529062487435188517811888011810686266227275489291486469864681111075608950696145276588771368435875508647514414202093638481872912380089977179381529628478320523519319142681504424059410890214500500647813935818925701905402605484098137956979368551025825239411318643997916523677044769662628646406540335627975329619264245079750470862462474091105444437355302146151475348090755330153269067933091699479889089824650841795567478606396975664557143737657027080403239977757865296846740093712377915770536094223688049108023244139183027962484411078464439516845227961935221269814753416782576455507316073751985374046064592546796043150737808314501684679758056905948759246368644416151863138085276603595816410945157599742077617618911601185155602080771746785959359879490191933389965271275403127925432247963269675912646103156343954375442792688936047041533537523137941310690833949767764290081333900380310406154723157882112449991673819054110440001",
"-6050060671375366504479199680125555354571111154849793880846497346573918278439742113929535410412245001",
"6050060671375366504479199680125555354571111154849793880846497346573918278439742113929535410412245001",
"Ett stort tal: 3055053912598508947549312393399320015114587255945938203336157885612484041009431069888461714759195551268559435567253681739042432883596095251201386787275483230684744081267827125833440603460902730356711375071354094223050737888829629366162631931903817637647689717474539783041913377052664360754530594685529992367990825283283974149969505378127988908031568501855509144132763267482753608051191973699171623938029652959112481486845481337238191540360720284661730596472758771447004611908440098952257078699946478448550527286513833176626948662169918947393179985715374284032316042361252971237912148029845209003214291118712054140346782303768450257172267231798011098225054231267262248662475182151309040596831972573353215246137318080262085035181877250579293515354614855964555777830248629948465567786086862810753702795567587162067253726096003964964500688100664251086317265876947315204732848217800469886468299762701072555744747779591654828652607439719426907428525310220609958805562225062879482109625089695394202628593497667989231655664335466686840002114903314366719176156379934652473163843885132940089748145111346970715322477428660266288621575724122801304127415652654106676287659899970936042983407271207522048301946054797801524409667398765473294408959679689184723792052760134847956855277232726822596118663268368339457701444058720789096452054802674735440411545784098932324643273016518451266202488737889642806430326763408371261207618736323003003074285732822242917868135329832468154778360696312466255598007468428021193037289627759263156774524144741442727509671028670105270271802796358516302383162038506066195947767590885980270531098318352386252200449553418183034106256724969986028116097882584686968836574809112315523792958340219637331628073406551777465246398555963295187086557808315091601583863758085230410601035610836375356201394730708447594526544296095311563361032030384261628391038148587272653017202863919268052007355101820880001",
"hej",
"hejsan",
"hej igen",
"hejsan igen"
]

  lib_script = callSample('bigIntegers.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i], "denna: " + output_lines[i] + ", verkligt: " + ric_result[i]
