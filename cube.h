#pragma once

static const int teapot_n_vertices = 3 * 8;
static const float teapot_vertices[teapot_n_vertices] = {
    0., 0., 0.,
    1., 0., 0.,
    1., 1., 0.,
    0., 1., 0.,
    0., 0., 1.,
    1., 0., 1.,
    1., 1., 1.,
    0., 1., 1.,
};

static const int teapot_n_indices = 3 * 12;
static const GLushort teapot_indices[teapot_n_indices] = {
        0, 3, 1,
        1, 3, 2,
        0, 4, 3,
        3, 4, 7,
        3, 7, 2,
        5, 1, 2,
        6, 5, 2,
        2, 5, 1,
        0, 1, 5,
        0, 5, 4,
        4, 5, 7,
        5, 6, 7
};
