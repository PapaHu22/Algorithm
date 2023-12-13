#include <stdio.h>
#include "emno.h"
#include "range.h"

void pst1(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                                                \n");
	printf("                 ##  ##              ##  ##                                              \n");
	printf("               ## [%d] ##           ## [%d] ##                                            \n", em[0].index,em[1].index);
	printf("                 ##  ##              ##  ##                                              \n");
	printf("                   ##                  ##                                                \n");
	printf("                %d/%d/%d            %d/%d/%d                                             \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index),em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("-----------------------------------------------------------------------------------------\n");
}

void pst2_1(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                             \n");
	printf("                          ##  ##              ##  ##                                           \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                           \n");
	printf("                            ##                  ##                                             \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}

void pst2_2(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                             \n");
	printf("                          ##  ##              ##  ##                                           \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                           \n");
	printf("                            ##                  ##                                             \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst3_1(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[3].index, em[4].index, em[5].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index), em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[0].index, em[1].index, em[2].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index), em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst3_2(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[3].index, em[4].index, em[5].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index), em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[0].index, em[1].index, em[2].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index), em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst3_3(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[3].index, em[4].index, em[5].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index), em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[0].index, em[1].index, em[2].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index), em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst4_1(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                             ##                  ##                           \n");
	printf("                           ##  ##              ##  ##                         \n");
	printf("                         ## [%d] ##           ## [%d] ##                       \n", em[5].index, em[6].index);
	printf("                           ##  ##              ##  ##                         \n");
	printf("                             ##                  ##                           \n");
	printf("                          %d/%d/%d            %d/%d/%d                        \n", em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index), em[6].HP, em[6].damage, shortest_path(&g, 0, em[6].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                               \n");
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                            ##                  ##                                               \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst4_2(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                             ##                  ##                           \n");
	printf("                           ##  ##              ##  ##                         \n");
	printf("                         ## [%d] ##           ## [%d] ##                       \n", em[5].index, em[6].index);
	printf("                           ##  ##              ##  ##                         \n");
	printf("                             ##                  ##                           \n");
	printf("                          %d/%d/%d            %d/%d/%d                        \n", em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index), em[6].HP, em[6].damage, shortest_path(&g, 0, em[6].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                               \n");
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                            ##                  ##                                               \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pst4_3(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                             ##                  ##                           \n");
	printf("                           ##  ##              ##  ##                         \n");
	printf("                         ## [%d] ##           ## [%d] ##                       \n", em[5].index, em[6].index);
	printf("                           ##  ##              ##  ##                         \n");
	printf("                             ##                  ##                           \n");
	printf("                          %d/%d/%d            %d/%d/%d                        \n", em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index), em[6].HP, em[6].damage, shortest_path(&g, 0, em[6].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                               \n");
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                            ##                  ##                                               \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}
void pboss(Em* em, GraphType g) {
	printf("-----------------------------------------------------------------------------------------\n");
	printf("체력/데미지/거리                                                                         \n");
	printf("                                     [보스]                                                   \n");
	printf("                                       ##                                             \n");
	printf("                                     ##  ##                                       \n");
	printf("                                   ## [%d] ##                                 \n", em[5].index);
	printf("                                     ##  ##                                      \n");
	printf("                                       ##                                             \n");
	printf("                                    %d/%d/%d                                    \n", em[5].HP, em[5].damage, shortest_path(&g, 0, em[5].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("               ## [%d] ##           ## [%d] ##           ## [%d] ##                       \n", em[2].index, em[3].index, em[4].index);
	printf("                 ##  ##              ##  ##              ##  ##                         \n");
	printf("                   ##                  ##                  ##                           \n");
	printf("                %d/%d/%d            %d/%d/%d            %d/%d/%d                        \n", em[2].HP, em[2].damage, shortest_path(&g, 0, em[2].index), em[3].HP, em[3].damage, shortest_path(&g, 0, em[3].index), em[4].HP, em[4].damage, shortest_path(&g, 0, em[4].index));
	printf("                                                                                         \n");
	printf("                                                                                         \n");
	printf("                            ##                  ##                                               \n");
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                        ## [%d] ##           ## [%d] ##                                         \n", em[0].index, em[1].index);
	printf("                          ##  ##              ##  ##                                             \n");
	printf("                            ##                  ##                                               \n");
	printf("                         %d/%d/%d            %d/%d/%d                                        \n", em[0].HP, em[0].damage, shortest_path(&g, 0, em[0].index), em[1].HP, em[1].damage, shortest_path(&g, 0, em[1].index));
	printf("-----------------------------------------------------------------------------------------\n");
}