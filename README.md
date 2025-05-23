# Programação Concorrente-entrega-2


**DADOS DE EXECUÇÃO**

Para N = 1000

|  Número de processadores |  Tempo na 1ª exec | Tempo na 2ª exec | Tempo na 3ª exec | Tempo na 4ª exec | Tempo na 5ª exec |    Tempo Médio  | Aceleração | Eficiência
|--------------------------|-------------------|------------------|------------------|------------------|------------------|-----------------|------------|------------
|            1             |       0.000847    |     0.000954     |      0.000829    |      0.000739    |     0.000898     | 0.0008534       | 1.000000   | 1.000000
|            2             |       0.000626    |     0.000783     |      0.000772    |      0.000861    |     0.000839     | 0.0007762       | 1.099458   | 0.549724 
|            3             |       0.000732    |     0.000734     |      0.000788    |      0.001024    |     0.000834     | 0.0008224       | 1.037694   | 0.345898
|            4             |       0.000860    |     0.000736     |      0.000809    |      0.000851    |     0.000994     | 0.00085         | 1.003866   | 0.250966
|            5             |       0.000748    |     0.000948     |      0.000845    |      0.001139    |     0.001046     | 0.0007452       | 1.144706   | 0.228941



Para N = 1000000

|  Número de processadores |  Tempo na 1ª exec | Tempo na 2ª exec | Tempo na 3ª exec | Tempo na 4ª exec | Tempo na 5ª exec |   Tempo Médio  | Aceleração | Eficiência
|--------------------------|-------------------|------------------|------------------|------------------|------------------|----------------|------------|------------
|            1             |       0.113182    |     0.118217     |      0.120292    |      0.117311    |     0.124296     | 0.118454       | 1.000000   | 1.000000
|            2             |       0.080177    |     0.077804     |      0.080321    |      0.078741    |     0.084477     | 0.080904       | 1.462679   | 0.731339
|            3             |       0.092721    |     0.096744     |      0.097452    |      0.089529    |     0.086984     | 0.092686       | 1.278679   | 0.426226
|            4             |       0.146168    |     0.119852     |      0.107597    |      0.134917    |     0.120133     | 0.125153       | 0.946679   | 0.236670
|            5             |       0.128629    |     0.142622     |      0.159675    |      0.148166    |     0.137644     | 0.143367       | 0.825679   | 0.165136




O cálculo do tempo foi feito usando o código que a professora disponibilizou no lab3 (timer.h)



Os gráficos estão separados por número de elementos. Assim para N=10³ os gráficos estão na pasta graficos_N=1000 e para 10⁶ na pasta graficos_N=1000000.

**CONFIGURAÇÕES DO COMPUTADOR**

Linux GHBRLPE0CTWED 6.8.0-57-generic #59~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Wed Mar 19 17:07:41 UTC 2 x86_64 x86_64 x86_64 GNU/Linux

Arquitetura:             x86_64

  CPU op-mode(s):         32-bit, 64-bit
  
  Address sizes:          46 bits physical, 48 bits virtual
  
  Byte Order:             Little Endian
  
CPU(s):                   12

  On-line CPU(s) list:    0-11
  
Vendor ID:                GenuineIntel

  Model name:             13th Gen Intel(R) Core(TM) i7-1365U
  
    CPU family:           6
    
    Model:                186
    
    Thread(s) per core:   2
    
    Core(s) per socket:   10
    
    Socket(s):            1
    
Caches:      

  L1d:                    352 KiB (10 instances)
  
  L1i:                    576 KiB (10 instances)
  
  L2:                     6,5 MiB (4 instances)
  
  L3:                     12 MiB (1 instance)
