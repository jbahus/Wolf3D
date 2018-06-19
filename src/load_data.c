/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:35:41 by jbahus            #+#    #+#             */
/*   Updated: 2018/06/06 15:35:43 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

t_xy	*realloc_vert(t_xy *vert, t_xy v, int *num_vertices)
{
	t_xy	*tmp;
	int		i;

	i = 0;
	tmp = (t_xy*)malloc(sizeof(t_xy*) * (*num_vertices));
	while (i < *num_vertices)
	{
		if (vert != NULL)
		{
			tmp[i] = vert[i];
		}
		// ft_putendl("");
		i++;
	}
	tmp[*num_vertices - 1] = v;
	if (vert != NULL)
		free(vert);
	vert = tmp;
	return (vert);
}

t_xy	*parse_vertex(char *str, t_xy *vert, int *num_vertices)
{
	t_xy	v;
	char	**tmp;
	char	**vert_x;
	int		i;

	i = 0;
	tmp = ft_strsplit(str, 9);
	vert_x = ft_strsplit(tmp[2], 32);
	if (vert_x == NULL)
	{
		*num_vertices += 1;
		v.y = ft_atoi(tmp[1]);
		v.x = ft_atoi(vert_x[i]);
		realloc_vert(vert, v, num_vertices);
		return (vert);
	}
	while(vert_x[i])
	{
		*num_vertices += 1;
		v.y = ft_atoi(tmp[1]);
		v.x = ft_atoi(vert_x[i]);
		vert = realloc_vert(vert, v, num_vertices);
		i++;
	}
	free(tmp);
	return (vert);
}


void	load_data(t_sectors **sect, t_player *player)
{
	int		fd;
	int		num_vertices;
	t_buff	buf;
	t_xy	*vert;
	int i = 0;

	vert = NULL;
	num_vertices = 0;
	if ((fd = open("maps/map.txt", O_RDONLY)) < 0)
	{
		perror("Can't read map");
		exit(1);
	}
	while (get_next_line(fd, &buf) > 0)
	{
		if (buf.data[0] == 'v')
		{
			vert = parse_vertex(buf.data, vert, &num_vertices);
		}
		else if (buf.data[0] == 'p')
		{

		}
		else if (buf.data[0] == 's')
		{

		}
	}
	close(fd);
	ft_putendl("ca passe");
	while (i < num_vertices){
		printf("y: %f\n", vert[i].y);
		printf("x: %f\n", vert[i].x);
		ft_putendl("");
		i++;
	}
	// free(vert);


	// FILE* fp = fopen("maps/map.txt", "rt");
 //    if(!fp) { perror("map.txt"); exit(1); }
 //    char Buf[256], word[256], *ptr;
 //    // struct t_xy *vert = NULL;
 //    t_xy v;
 //    int n, m, NumVertices = 0;
 //    while(fgets(Buf, sizeof Buf, fp))
 //        switch(sscanf(ptr = Buf, "%32s%n", word, &n) == 1 ? word[0] : '\0')
 //        {
 //            case 'v': // vertex
 //                for(sscanf(ptr += n, "%f%n", &v.y, &n); sscanf(ptr += n, "%f%n", &v.x, &n) == 1; )
 //                    {
 //                    	vert = realloc(vert, ++NumVertices * sizeof(*vert)); vert[NumVertices-1] = v;
 //                    }
 //                break;
 //            case 's': // sector
 //                // sectors = realloc(sectors, ++NumSectors * sizeof(*sectors));
 //                // struct sector* sect = &sectors[NumSectors-1];
 //                // int* num = NULL;
 //                // sscanf(ptr += n, "%f%f%n", &sect->floor,&sect->ceil, &n);
 //                // for(m=0; sscanf(ptr += n, "%32s%n", word, &n) == 1 && word[0] != '#'; )
 //                //     { num = realloc(num, ++m * sizeof(*num)); num[m-1] = word[0]=='x' ? -1 : atoi(word); }
 //                // sect->npoints   = m /= 2;
 //                // sect->neighbors = malloc( (m  ) * sizeof(*sect->neighbors) );
 //                // sect->vertex    = malloc( (m+1) * sizeof(*sect->vertex)    );
 //                // for(n=0; n<m; ++n) sect->neighbors[n] = num[m + n];
 //                // for(n=0; n<m; ++n) sect->vertex[n+1]  = vert[num[n]]; // TODO: Range checking
 //                // sect->vertex[0] = sect->vertex[m]; // Ensure the vertexes form a loop
 //                // free(num);
 //                break;
 //            case 'p':; // player
 //                // float angle;
 //                // sscanf(ptr += n, "%f %f %f %d", &v.x, &v.y, &angle,&n);
 //                // player = (struct player) { {v.x, v.y, 0}, {0,0,0}, angle,0,0,0, n }; // TODO: Range checking
 //                // player.where.z = sectors[player.sector].floor + EyeHeight;
 //        }
 //    fclose(fp);
 //    free(vert);
}